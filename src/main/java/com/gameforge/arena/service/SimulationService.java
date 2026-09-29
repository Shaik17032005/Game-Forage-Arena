package com.gameforge.arena.service;

import org.springframework.stereotype.Service;
import javax.annotation.PostConstruct;

@Service
public class SimulationService {

    // Load the C++ native library
    static {
        try {
            System.loadLibrary("GameSimulation"); // This will look for GameSimulation.dll (Windows), libGameSimulation.so (Linux), or libGameSimulation.dylib (Mac)
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load.\n" + e);
        }
    }

    // Native method to initialize the simulation engine
    public native void initSimulationEngine();

    // Native method to process game tick
    public native void processGameTick(int tickId);

    // Native method for optimized matchmaking evaluation
    public native double evaluateMatch(int playerRatingA, int playerRatingB);

    @PostConstruct
    public void init() {
        try {
            initSimulationEngine();
            System.out.println("C++ Simulation Engine initialized via JNI.");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Could not initialize simulation engine. DLL not found.");
        }
    }
}
