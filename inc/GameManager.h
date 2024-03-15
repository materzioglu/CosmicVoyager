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
#include <iostream>
#include <array>
#include "Definition.h"

class GameManager {
public:
    static int generateRandomNumber(int _limit);
    void initializeGameManager();
    int startGame();
    bool checkFuel();
    double getGameScore();
    void printGameResult();
    void printCurrentValues();
    std::shared_ptr<SpaceShip> chooseShip();
    std::shared_ptr<GameEvent> callEvent();

private:


protected:
    std::shared_ptr<SpaceShip> _chosenShip;
    std::shared_ptr<GameEvent> _calledEvent;
};


#endif //COSMICVOYAGER_GAMEMANAGER_H
