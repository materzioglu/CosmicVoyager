//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_STRONGSHIP_H
#define COSMICVOYAGER_STRONGSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class StrongShip : public SpaceShip {
public:
    StrongShip() : SpaceShip(0.5, "Strong Ship") {}

    void printShipInfo() const override {
        std::cout << "The ship coefficient of the " << _name <<" is " << _shipCoefficient;
        std::cout << ". Default values of escape probability and damage are multiplied by " << _shipCoefficient << ".\n";
    }

private:
protected:
};

#endif //COSMICVOYAGER_STRONGSHIP_H