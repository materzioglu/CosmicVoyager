cmake_minimum_required(VERSION 3.27)
project(CosmicVoyager)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

add_executable(CosmicVoyager main.cpp
        inc/SpaceShip.h
        inc/GameManager.h
        inc/GameEvent.h
        inc/StrongShip.h
        inc/NormalShip.h
        inc/AsteroidBelt.h
        inc/AbandonedPlanet.h
        inc/SpacePirates.h
        inc/FastShip.h
        src/AsteroidBelt.cpp
        src/AbandonedPlanet.cpp
        src/SpacePirates.cpp
        src/GameManager.cpp
        inc/Definition.h)
