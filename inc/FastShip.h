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

    bool checkFuel() override {
        const double leastFuel{0.0};
        return _fuel > leastFuel;
    }

private:
protected:
};

#endif //COSMICVOYAGER_FASTSHIP_H
