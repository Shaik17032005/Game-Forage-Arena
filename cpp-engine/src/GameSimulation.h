#ifndef GAME_SIMULATION_H
#define GAME_SIMULATION_H

class GameSimulation {
public:
    static void init();
    static void processTick(int tickId);
    static double evaluateMatchQuality(int ratingA, int ratingB);
};

#endif // GAME_SIMULATION_H
