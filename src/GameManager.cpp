//
// Created by Oem on 13.03.2024.
//

#include <iostream>
#include <limits>
#include "GameManager.h"

int GameManager::startGame() {
    int shipType{0};
    std::cout << "Welcome to the Cosmic Voyager. You will be a captain of a space ship and experience some exciting events.\n";
    std::cout << "At first, you need to choose the type of your space ship.\n\n";
    addSpaceShip();
    addGameEvent();
    printAllShipInfo();
    while(true) {
        std::cout << "\nPlease enter (1) for Normal Ship, (2) for Fast Ship, and (3) for Strong Ship.\n";
        std::cin >> shipType;
        if(std::cin.fail() || !((shipType == 1) || (shipType == 2) || (shipType == 3))) {
            std::cout << "This is an invalid value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return shipType;
}

void GameManager::printAllShipInfo() {
    for(auto spaceShip : spaceShipVector) {
        spaceShip->printShipInfo();
    }
}

void GameManager::addSpaceShip() {
    spaceShipVector.emplace_back(std::make_shared<NormalShip>());
    spaceShipVector.emplace_back(std::make_shared<FastShip>());
    spaceShipVector.emplace_back(std::make_shared<StrongShip>());
}

void GameManager::addGameEvent() {
    gameEventVector.emplace_back(std::make_shared<AsteroidBelt>());
    gameEventVector.emplace_back(std::make_shared<AbandonedPlanet>());
    gameEventVector.emplace_back(std::make_shared<SpacePirates>());
}

void GameManager::chooseShip() {
    int chosenType = startGame();
    _chosenShip = spaceShipVector[chosenType - 1];
    std::cout << "You chose " << _chosenShip->getName() << ". Let's start!\n";
}

void GameManager::callEvent() {
    const int minValue{0};
    const int maxValue{2};
    int chosenEvent = Utilities::generateRandomInteger(minValue, maxValue);
    _calledEvent = gameEventVector[chosenEvent];
}

void GameManager::initializeGameManager() {
    chooseShip();
    Utilities::printCurrentValues(*_chosenShip);
    const int callingAmount{5};
    for(int i = 0; i < callingAmount; i++) {
        std::cout << "EVENT: " << i + 1 << "\n";
        callEvent();
        int eventResult = _calledEvent->executeEvent(_chosenShip);
        if(eventResult == AP_CALL_SPACE_PIRATES) {
            _calledEvent = gameEventVector[SPACE_PIRATES];
            _calledEvent->executeEvent(_chosenShip);
        }
        if(!Utilities::checkFuel(*_chosenShip)) {
            break;
        }
        Utilities::printCurrentValues(*_chosenShip);
    }
    printGameResult();
}

double GameManager::getGameScore() {
    const double fuelCoefficient{5.0};
    const double healthCoefficient{10.0};
    const double moneyCoefficient{10.0};
    double score = _chosenShip->getFuel() * fuelCoefficient + _chosenShip->getHealth() * healthCoefficient + _chosenShip->getMoney() * moneyCoefficient;
    return score;
}

void GameManager::printGameResult() {
    double score = getGameScore();
    std::cout << "Game is over. Your score: " << score;
}