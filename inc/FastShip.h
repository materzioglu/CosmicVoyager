//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_FASTSHIP_H
#define COSMICVOYAGER_FASTSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class FastShip : public SpaceShip {
public:
    FastShip() : SpaceShip(1.5, "Fast Ship") {}

    void printShipInfo() const override {
        std::cout << "For the " << _name <<" the ship coefficient is: " << _shipCoefficient;
        std::cout << ". Default values are multiplied by " << _shipCoefficient << " for escape probability and damage.\n";
    }

private:
protected:
};

#endif //COSMICVOYAGER_FASTSHIP_H