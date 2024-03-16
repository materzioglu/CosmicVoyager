//
// Created by Oem on 13.03.2024.
//

#include <iostream>
#include <limits>
#include "GameManager.h"

int GameManager::startGame() {
    int shipType{0};
    std::cout << "Welcome to the Cosmic Voyager. You will be a captain of a space ship and experience some exciting events.\n";
    std::cout << "At first, you need to choose the type of your space ship.\n";
    while(true) {
        std::cout << "Please enter (1) for normal ship, (2) for fast ship, and (3) for strong ship.\n";
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

std::shared_ptr<SpaceShip> GameManager::chooseShip() {
    int chosenType = startGame();
    std::shared_ptr<SpaceShip> chosenShip;
    switch (chosenType) {
        case 1:
            chosenShip = std::make_shared<NormalShip>();
            break;
        case 2:
            chosenShip = std::make_shared<FastShip>();
            break;
        case 3:
            chosenShip = std::make_shared<StrongShip>();
            break;
    }
    std::cout << "\nYou chose " << chosenShip->getName() << ". Let's start!\n\n";
    return chosenShip;
}

std::shared_ptr<GameEvent> GameManager::callEvent() {
    const int minValue{1};
    const int maxValue{3};
    int chosenEvent = Utilities::generateRandomInteger(minValue, maxValue);
    std::shared_ptr<GameEvent> calledEvent;
    switch (chosenEvent) {
        case 1:
            calledEvent = std::make_shared<AsteroidBelt>();
            break;
        case 2:
            calledEvent = std::make_shared<AbandonedPlanet>();
            break;
        case 3:
            calledEvent = std::make_shared<SpacePirates>();
            break;
    }
    return calledEvent;
}

void GameManager::initializeGameManager() {
    _chosenShip = chooseShip();
    const int callingAmount{5};
    for(int i = 0; i < callingAmount; i++) {
        std::cout << "EVENT: " << i + 1 << "\n";
        _calledEvent = callEvent();
        int eventResult = _calledEvent->executeEvent(_chosenShip);
        if(eventResult == AP_CALL_SPACE_PIRATES) {
            _calledEvent = std::make_shared<SpacePirates>();
            _calledEvent->executeEvent(_chosenShip);
        }
        if(!_chosenShip->checkFuel()) {
            break;
        }
        Utilities::printCurrentValues(*_chosenShip);
    }
    printGameResult();
}

double GameManager::getGameScore() {
    double currentFuel{_chosenShip->getFuel()};
    double currentHealth{_chosenShip->getHealth()};
    double currentMoney{_chosenShip->getMoney()};
    const int fuelCoefficient{5};
    const int healthCoefficient{10};
    const int moneyCoefficient{10};
    double score = currentFuel * fuelCoefficient + currentHealth * healthCoefficient + currentMoney * moneyCoefficient;
    return score;
}

void GameManager::printGameResult() {
    double score = getGameScore();
    std::cout << "Game is over. Your score: " << score;
}