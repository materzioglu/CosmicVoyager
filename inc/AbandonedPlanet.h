//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_ABANDONEDPLANET_H
#define COSMICVOYAGER_ABANDONEDPLANET_H
#include <iostream>
#include <memory>
#include "SpaceShip.h"
#include "GameEvent.h"
#include "GameManager.h"
#include "Definition.h"
#include "Utilities.h"

class AbandonedPlanet : public GameEvent {
public:
    AbandonedPlanet() = default;

    int executeEvent(std::shared_ptr<SpaceShip> chosenShip) override;

private:
protected:
};


#endif //COSMICVOYAGER_ABANDONEDPLANET_H
