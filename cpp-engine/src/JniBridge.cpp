#include <jni.h>
#include "GameSimulation.h"

extern "C" {

JNIEXPORT void JNICALL Java_com_gameforge_arena_service_SimulationService_initSimulationEngine(JNIEnv *env, jobject thisObj) {
    GameSimulation::init();
}

JNIEXPORT void JNICALL Java_com_gameforge_arena_service_SimulationService_processGameTick(JNIEnv *env, jobject thisObj, jint tickId) {
    GameSimulation::processTick(tickId);
}

JNIEXPORT jdouble JNICALL Java_com_gameforge_arena_service_SimulationService_evaluateMatch(JNIEnv *env, jobject thisObj, jint ratingA, jint ratingB) {
    return GameSimulation::evaluateMatchQuality(ratingA, ratingB);
}

}
