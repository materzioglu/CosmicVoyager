//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_GAMEEVENT_H
#define COSMICVOYAGER_GAMEEVENT_H
#include "SpaceShip.h"
#include "Definition.h"
#include <memory>

class GameEvent {
public:
    GameEvent() = default;

    virtual int executeEvent(std::shared_ptr<SpaceShip> chosenShip) = 0;

private:


protected:

};

#endif //COSMICVOYAGER_GAMEEVENT_H
