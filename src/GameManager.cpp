//
// Created by Oem on 13.03.2024.
//

#include <iostream>
#include <windows.h>
#include "GameManager.h"

int GameManager::generateRandomNumber(int _limit) {
    int generatedNumber = rand() % _limit + 1; // rand() % limit generates a number between 0 and limit - 1
    return generatedNumber;
}

int GameManager::startGame() {
    int shipType{0};
    std::cout << "Welcome to the Cosmic Voyager. You will be a captain of a space ship and experience some exciting events.\n";
    std::cout << "At first, you need to choose the type of your space ship. Please enter (1) for normal ship, (2) for fast ship, and (3) for strong ship.\n";
    std::cin >> shipType;
    while(!((shipType == 1) || (shipType == 2) || (shipType == 3))) {
        std::cout << "This is an invalid value. Please enter (1) for normal ship, (2) for fast ship, and (3) for strong ship.\n";
        std::cin >> shipType;
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
    std::cout << "\nYou chose ";
    chosenShip->getShipName();
    std::cout << ". Let's start!\n\n";
    return chosenShip;
}

std::shared_ptr<GameEvent> GameManager::callEvent() {
    int chosenEvent = generateRandomNumber(3);
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
    for(int i = 0; i < 5; i++) {
        std::cout << "EVENT: " << i + 1 << "\n";
        _calledEvent = callEvent();
        int eventResult = _calledEvent->executeEvent(_chosenShip);
        if(eventResult == AP_CALL_SPACE_PIRATES) {
            _calledEvent = std::make_shared<SpacePirates>();
            _calledEvent->executeEvent(_chosenShip);
        }
        if(!checkFuel()) {
            break;
        }
        std::cout << "\n";
        printCurrentValues();
        std::cout << "\n";
    }
    printGameResult();
}

double GameManager::getGameScore() {
    double currentFuel{_chosenShip->getFuel()};
    double currentHealth{_chosenShip->getHealth()};
    double currentMoney{_chosenShip->getMoney()};
    double score = currentFuel * 5 + currentHealth * 10 + currentMoney * 10;
    return score;
}

void GameManager::printGameResult() {
    double score = getGameScore();
    std::cout << "Game is over. Your score: " << score;
}

void GameManager::printCurrentValues() {
    std::cout << "Current fuel: " << _chosenShip->getFuel() << "\n";
    std::cout << "Current health: " << _chosenShip->getHealth() << "\n";
    std::cout << "Current money: " << _chosenShip->getMoney() << "\n\n";
}

bool GameManager::checkFuel() {
    double currentFuel{_chosenShip->getFuel()};
//    return currentFuel > 0;
    if(currentFuel <= 0){
        return false;
    }
    else {
        return true;
    }
}