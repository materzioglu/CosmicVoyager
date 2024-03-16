//
// Created by Oem on 15.03.2024.
//

#include <iostream>
#include <random>
#include "Utilities.h"

int Utilities::generateRandomInteger(int start, int stop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(start, stop);
    return distrib(gen);
    // C++11 random library
    // This function generates an integer in the range [start, stop].
}

double Utilities::generateRandomDouble(double start, double stop) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(start,stop);
    return dis(gen);
    // C++11 random library
    // This function generates a double in the range [start, stop).
}

bool Utilities::checkFuel(SpaceShip& spaceShip) {
    const double leastFuel{0.0};
    return spaceShip.getFuel() > leastFuel;
}

void Utilities::printCurrentValues(SpaceShip& spaceShip) {
    std::cout << "\nCurrent fuel: " << spaceShip.getFuel() << "\n";
    std::cout << "Current health: " << spaceShip.getHealth() << "\n";
    std::cout << "Current money: " << spaceShip.getMoney() << "\n\n";
}