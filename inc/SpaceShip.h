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
    SpaceShip(double shipCoefficient, std::string name) : _shipCoefficient{shipCoefficient}, _name{name} {
        _fuel = 100.0;
        _health = 100.0;
        _money = 0.0;
    }

    virtual ~SpaceShip() = default;

    virtual void printShipInfo() const = 0;

    std::string getName() {
        return _name;
    }

    double getFuel() {
        return _fuel;
    }
    void setFuel(double fuel) {
        _fuel = fuel;
    }

    double getHealth() {
        return _health;
    }
    void setHealth(double health) {
        _health = health;
    }

    double getMoney() {
        return _money;
    }
    void setMoney(double money) {
        _money = money;
    }

    double getShipCoefficent() {
        return _shipCoefficient;
    }

private:
protected:
    std::string _name;
    double _fuel;
    double _health;
    double _money;
    double _shipCoefficient;
};

#endif //COSMICVOYAGER_SPACESHIP_H