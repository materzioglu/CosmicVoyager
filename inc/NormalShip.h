//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_NORMALSHIP_H
#define COSMICVOYAGER_NORMALSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class NormalShip : public SpaceShip {
public:
    NormalShip() : SpaceShip(1.0) {}

    void getShipName() const override {
        std::cout << "Normal Ship";
    }

private:
protected:
};

#endif //COSMICVOYAGER_NORMALSHIP_H
