//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include "AsteroidBelt.h"

int AsteroidBelt::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You are about to go through the Asteroid Belt. This event will be happened 3 times. You might get damaged. Good luck.\n";
    double damage{0.0};
    double defaultDamage{10.0};
    double changedHealth{chosenShip->getHealth()};
    const int callingAmount{3};
    for (int i = 0; i < callingAmount; i++) {
        int option = GameManager::generateRandomNumber(2);
        if (option == 2) {
            damage += defaultDamage * chosenShip->getShipCoefficent();
        }
    }
    changedHealth -= damage;
    chosenShip->setHealth(changedHealth);
    return CONTINUE;
}