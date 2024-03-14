//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_FASTSHIP_H
#define COSMICVOYAGER_FASTSHIP_H
#include "SpaceShip.h"
#include "Definition.h"

class FastShip : public SpaceShip {
public:
    FastShip() : SpaceShip(1.5) {}
    void displayStatus() const override {
        std::cout << "Fast ship";
    }
private:
protected:
};

#endif //COSMICVOYAGER_FASTSHIP_H
