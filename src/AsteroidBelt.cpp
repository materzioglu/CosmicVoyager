//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include "AsteroidBelt.h"

int AsteroidBelt::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You are about to go through the Asteroid Belt. This event will be happened 3 times. You might get damaged. Good luck.\n";
    double damage{0.0};
    double changedHealth{chosenShip->getHealth()};
    int counter{0};
    const double defaultDamage{10.0};
    const int callingAmount{3};
    const int minValue{1};
    const int maxValue{2};
    for (int i = 0; i < callingAmount; ++i) {
        int option = Utilities::generateRandomInteger(minValue, maxValue);
        if (option == 1) {
            damage += defaultDamage * chosenShip->getShipCoefficent();
            counter++;
        }
    }
    std::cout << "You got damaged " << counter << " times.\n";
    std::cout << "Total damage you got in the Asteroid Belt: " << damage << "\n";
    changedHealth -= damage;
    chosenShip->setHealth(changedHealth);
    return CONTINUE;
}