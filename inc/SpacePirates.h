//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_SPACEPIRATES_H
#define COSMICVOYAGER_SPACEPIRATES_H
#include <iostream>
#include <memory>
#include "SpaceShip.h"
#include "GameEvent.h"
#include "GameManager.h"
#include "Definition.h"

class SpacePirates : public GameEvent {
public:
    SpacePirates() = default;

    int executeEvent(std::shared_ptr<SpaceShip> chosenShip);
    int chooseOption();

private:
protected:
};


#endif //COSMICVOYAGER_SPACEPIRATES_H
