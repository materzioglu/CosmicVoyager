//
// Created by Oem on 15.03.2024.
//

#ifndef COSMICVOYAGER_UTILITIES_H
#define COSMICVOYAGER_UTILITIES_H
#include "SpaceShip.h"

class Utilities {
public:
    static int generateRandomInteger(int start, int stop);
    static bool checkFuel(SpaceShip& spaceShip);
    static void printCurrentValues(SpaceShip& spaceShip);

private:
protected:
};

#endif //COSMICVOYAGER_UTILITIES_H