//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include <limits>
#include "SpacePirates.h"

int SpacePirates::choose3Option() {
    int option{0};
    while(true) {
        std::cout << "Please enter (1) for running away, (2) for fighting, and (3) for bargaining.\n";
        std::cin >> option;
        if(std::cin.fail() || !((option == SP_RUN_AWAY) || (option == SP_FIGHT) || (option == SP_BARGAIN))) {
            std::cout << "This is an invalid value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return option;
}

int SpacePirates::choose2Option() {
    int option{0};
    while(true) {
        std::cout << "Please enter (2) for fighting, and (3) for bargaining.\n";
        std::cin >> option;
        if(std::cin.fail() || !((option == SP_FIGHT) || (option == SP_BARGAIN))) {
            std::cout << "This is an invalid value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return option;
}

int SpacePirates::chooseRunAway(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You are going to try running away. Good luck.\n";
    const double requiredFuel{33.0};
    const int defaultEscapeProbability{50};
    const int minValue{0};
    const int maxValue{99};
    double changedFuel{chosenShip->getFuel()};
    double escapeProbability = Utilities::generateRandomInteger(minValue, maxValue);
    if(changedFuel >= requiredFuel) {
        if(escapeProbability < defaultEscapeProbability * chosenShip->getShipCoefficent()){
            std::cout << "Congrats! You are able to run away from the space pirates.\n";
            changedFuel -= requiredFuel;
            chosenShip->setFuel(changedFuel);
            return CONTINUE;
        }
        else {
            return SP_RUN_AWAY_FAILED;
        }
    }
    else {
        return SP_RUN_AWAY_INADEQUATE_FUEL;
    }
}

int SpacePirates::chooseFight(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You are going to fight. Good luck.\n";
    double changedHealth{chosenShip->getHealth()};
    const double defaultDamage{30.0};
    const int minValue{1};
    const int maxValue{2};
    int escapeProbability = Utilities::generateRandomInteger(minValue, maxValue);
    if(escapeProbability == 1) {
        std::cout << "Congrats! You win.\n";
    }
    else {
        std::cout << "Sorry, you loosed the fight.\n";
        changedHealth -= defaultDamage * chosenShip->getShipCoefficent();
        chosenShip->setHealth(changedHealth);
    }
    return CONTINUE;
}

int SpacePirates::chooseBargain(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You are going to bargain. Good luck.\n";
    double changedMoney{chosenShip->getMoney()};
    const int minValue{1};
    const int maxValue{3};
    double payment = static_cast<double>(Utilities::generateRandomInteger(minValue, maxValue)) * 10.0;
    if(changedMoney >= payment){
        changedMoney -= payment;
        chosenShip->setMoney(changedMoney);
        std::cout << "You pay " << payment << " to space pirates.\n";
        return CONTINUE;
    }
    else {
        std::cout << "You do not have enough money to pay. You have to fight.\n";
        return SP_BARGAIN_CALL_FIGHT;
    }
}

int SpacePirates::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You encounter with space pirates. ";
    int option = choose3Option();
    int eventResult{0};
    while(true) {
        if(option == SP_RUN_AWAY) {
            eventResult = chooseRunAway(chosenShip);
            if(eventResult == CONTINUE) {
                break;
            }
            else if(eventResult == SP_RUN_AWAY_FAILED) {
                std::cout << "Unfortunately, you cannot be able to run away from the space pirates. You encounter with space pirates again.\n";
                option = choose3Option();
            }
            else {
                std::cout << "You do not have enough fuel. So, you cannot choose to run away.\n";
                option = choose2Option();
            }
        }
        else if(option == SP_FIGHT) {
            chooseFight(chosenShip);
            break;
        }
        else if(option == SP_BARGAIN) {
            eventResult = chooseBargain(chosenShip);
            if(eventResult == CONTINUE) {
                break;
            }
            else {
                option = SP_FIGHT;
            }
        }
    }
    return CONTINUE;
}