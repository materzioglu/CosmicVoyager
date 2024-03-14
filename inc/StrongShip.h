//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_STRONGSHIP_H
#define COSMICVOYAGER_STRONGSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class StrongShip : public SpaceShip {
public:
    StrongShip() : SpaceShip(0.5) {}
    void displayStatus() const override{
        std::cout << "Strong ship";
    }

private:
protected:
};

#endif //COSMICVOYAGER_STRONGSHIP_H
