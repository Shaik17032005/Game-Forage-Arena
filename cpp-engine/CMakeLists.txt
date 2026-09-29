cmake_minimum_required(VERSION 3.10)
project(GameSimulation VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find JNI
find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})

# Create the shared library (.dll / .so)
add_library(GameSimulation SHARED
    src/JniBridge.cpp
    src/GameSimulation.cpp
)
