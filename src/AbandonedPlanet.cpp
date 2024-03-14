//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include "AbandonedPlanet.h"

int AbandonedPlanet::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "Abandoned planet\n";
    double gain{10.0};
    double changedMoney{chosenShip->getMoney()};
    int option = GameManager::generateRandomNumber(2);
    if(option == 1) {
        changedMoney += gain;
        chosenShip->setMoney(changedMoney);
        std::cout << "You gain.\n";
        return CONTINUE;
    }
    else if(option == 2) {
        std::cout << "Call space pirates.\n";
        return AP_CALL_SPACE_PIRATES;
    }
}