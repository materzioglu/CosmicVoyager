//
// Created by Oem on 11.03.2024.
//

#ifndef COSMICVOYAGER_SPACESHIP_H
#define COSMICVOYAGER_SPACESHIP_H

#include <iostream>
#include <string>
#include <utility>
#include "Definition.h"

class SpaceShip {
public:
    SpaceShip(double _shipCoefficient, std::string name) : shipCoefficient{_shipCoefficient}, _name{name} {
        _fuel = 100;
        health = 100;
        money = 0;
    }

    virtual ~SpaceShip() = default;

    virtual bool checkFuel() = 0;
 //   virtual void getShipName() const = 0;

    std::string getName() {
        return _name;
    }

    void setName(std::string name) {
        _name = name;
    }

    double getFuel() {
        return _fuel;
    }
    void setFuel(double _fuel) {
        _fuel = _fuel;
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
    std::string _name;
    double _fuel;
    double health;
    double money;
    double shipCoefficient;
};

#endif //COSMICVOYAGER_SPACESHIP_H
