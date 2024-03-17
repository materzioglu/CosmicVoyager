//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_GAMEMANAGER_H
#define COSMICVOYAGER_GAMEMANAGER_H
#include "SpaceShip.h"
#include "GameEvent.h"
#include "NormalShip.h"
#include "FastShip.h"
#include "StrongShip.h"
#include "AsteroidBelt.h"
#include "AbandonedPlanet.h"
#include "SpacePirates.h"
#include <memory>
#include <vector>
#include <iostream>
#include <array>
#include "Definition.h"
#include "Utilities.h"

class GameManager {
public:
    void initializeGameManager();
    static int startGame();
    double getGameScore();
    void printGameResult();
    void addSpaceShip();
    void addGameEvent();
    void chooseShip();
    void callEvent();
    std::vector<std::shared_ptr<SpaceShip>> spaceShipVector;
    std::vector<std::shared_ptr<GameEvent>> gameEventVector;

private:


protected:
    std::shared_ptr<SpaceShip> _chosenShip;
    std::shared_ptr<GameEvent> _calledEvent;
};


#endif //COSMICVOYAGER_GAMEMANAGER_H