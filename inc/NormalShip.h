//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_NORMALSHIP_H
#define COSMICVOYAGER_NORMALSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class NormalShip : public SpaceShip {
public:
    NormalShip() : SpaceShip(1.0, "Normal Ship") {}

    void printShipInfo() const override {
        std::cout << "For the " << _name <<" the ship coefficient is: " << _shipCoefficient;
        std::cout << ". Default values are used for escape probability and damage.\n";
    }

private:
protected:
};

#endif //COSMICVOYAGER_NORMALSHIP_H