//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_ASTEROIDBELT_H
#define COSMICVOYAGER_ASTEROIDBELT_H
#include <iostream>
#include <memory>
#include "SpaceShip.h"
#include "GameEvent.h"
#include "GameManager.h"
#include "Definition.h"

class AsteroidBelt : public GameEvent {
public:
    AsteroidBelt() = default;

    int executeEvent(std::shared_ptr<SpaceShip> chosenShip);

private:


protected:
};

#endif //COSMICVOYAGER_ASTEROIDBELT_H
