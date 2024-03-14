//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_SPACESHIP_H
#define COSMICVOYAGER_SPACESHIP_H

#include <iostream>
#include <string>
#include "Definition.h"

class SpaceShip {
public:
    SpaceShip(double _shipCoefficient) : shipCoefficient{_shipCoefficient} {
        fuel = 100;
        health = 100;
        money = 0;
    }

    virtual ~SpaceShip() = default;

    virtual void displayStatus() const = 0;

    double getFuel() {
        return fuel;
    }
    void setFuel(double _fuel) {
        fuel = _fuel;
    }

    double getHealth() {
        return health;
    }
    void setHealth(double _health) {
        health = _health;
    }

    double getMoney() {
        return money;
    }
    void setMoney(double _money) {
        money = _money;
    }

    double getShipCoefficent() {
        return shipCoefficient;
    }
    void setShipCoefficient(double _shipCoefficient) {
        shipCoefficient = _shipCoefficient;
    }

private:

protected:
    double fuel;
    double health;
    double money;
    double shipCoefficient;
};

#endif //COSMICVOYAGER_SPACESHIP_H
