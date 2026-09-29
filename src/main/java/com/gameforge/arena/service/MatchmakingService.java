package com.gameforge.arena.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

@Service
public class MatchmakingService {

    private final Queue<String> matchmakingQueue = new ConcurrentLinkedQueue<>();
    private final SimulationService simulationService;

    @Autowired
    public MatchmakingService(SimulationService simulationService) {
        this.simulationService = simulationService;
    }

    public void queuePlayer(String playerId, int rating) {
        matchmakingQueue.offer(playerId);
        System.out.println("Player " + playerId + " added to queue with rating " + rating);
        
        // Example of using the C++ optimized matching logic
        try {
            double matchQuality = simulationService.evaluateMatch(rating, 1500); // 1500 is a mock opponent rating
            System.out.println("C++ Match Quality Evaluation vs 1500: " + matchQuality);
        } catch (UnsatisfiedLinkError e) {
            // Ignore during simple Java run without DLL
        }
    }

    public int getQueueSize() {
        return matchmakingQueue.size();
    }
}
