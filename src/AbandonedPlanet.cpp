//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include "AbandonedPlanet.h"

int AbandonedPlanet::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You come to the Abandoned Planet. You will gain money or encounter with space pirates.\n";
    const double gain{10.0};
    double changedMoney{chosenShip->getMoney()};
    const int randOptionLimit{2};
    int option = GameManager::generateRandomNumber(randOptionLimit);
    if(option == 1) {
        changedMoney += gain;
        chosenShip->setMoney(changedMoney);
        std::cout << "Congrats! You gain money.\n";
        return CONTINUE;
    }
    else if(option == 2) {
        return AP_CALL_SPACE_PIRATES;
    }
}