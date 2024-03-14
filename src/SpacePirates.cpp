//
// Created by Oem on 11.03.2024.
//

#include <iostream>
#include "SpacePirates.h"

int SpacePirates::chooseOption() {
    int option{0};
    std::cout << "Please enter (1) for running away, (2) for fighting, and (3) for bargaining.\n";
    std::cin >> option;
    while(!((option == SP_RUN) || (option == SP_FIGHT) || (option == SP_BARGAIN))) {
        std::cout << "This is an invalid value. Please enter (1) for running away, (2) for fighting, and (3) for bargaining.\n";
        std::cin >> option;
    }
    return option;
}

//int SpacePirates::choose1of2() {
//    int option{0};
//    std::cout << "Please enter (2) for fighting, and (3) for bargaining.\n";
//    std::cin >> option;
//    while(!((option == SP_FIGHT) || (option == SP_BARGAIN))) {
//        std::cout << "This is an invalid value. Please enter (2) for fighting, and (3) for bargaining.\n";
//        std::cin >> option;
//    }
//    return option;
//}
//
//int SpacePirates::runAway(std::shared_ptr<SpaceShip> chosenShip) {
//    double requiredFuel{33.0};
//    double changedFuel{chosenShip->getFuel()};
//    double defaultEscapeProbability{0.5};
//    double escapeProbability = (GameManager::generateRandomNumber(101) - 1) / 100;
//    std::cout << "You chose to try running away. Good luck.\n";
//    if(chosenShip->getFuel() >= requiredFuel) {
//        if(escapeProbability < defaultEscapeProbability * chosenShip->getShipCoefficent()){
//            std::cout << "Congrats! You are able to run away from the space pirates.\n";
//            changedFuel -= requiredFuel;
//            chosenShip->setFuel(changedFuel);
//            std::cout << "Remaining fuel: " << changedFuel << "\n";
//        }
//        else {
//            std::cout << "Unfortunately, you cannot be able to run away from the space pirates. You encounter with space pirates again.\n";
//        }
//    }
//    else {
//        std::cout << "You do not have enough fuel. So you cannot choose to run away.\n";
//        int option = choose1of2();
//    }
//}
//
//int SpacePirates::fight(std::shared_ptr<SpaceShip> chosenShip) {
//
//}
//
//int SpacePirates::bargain(std::shared_ptr<SpaceShip> chosenShip) {
//
//}

int SpacePirates::executeEvent(std::shared_ptr<SpaceShip> chosenShip) {
    std::cout << "You encounter with space pirates. ";
    int option = chooseOption();
    const double requiredFuel{33.0};
    double changedFuel{chosenShip->getFuel()};
    double changedHealth{chosenShip->getHealth()};
    double changedMoney{chosenShip->getMoney()};
    const double defaultEscapeProbability{0.5};
    const double defaultDamage{30.0};
    double escapeProbability{0.0};
    while(true) {
        escapeProbability = static_cast<double>((GameManager::generateRandomNumber(101) - 1)) / 100;
        if(option == SP_RUN) {
            std::cout << "You are going to try running away. Good luck.\n";
            if(chosenShip->getFuel() >= requiredFuel) {
                if(escapeProbability < defaultEscapeProbability * chosenShip->getShipCoefficent()){
                    std::cout << "Congrats! You are able to run away from the space pirates.\n";
                    changedFuel -= requiredFuel;
                    chosenShip->setFuel(changedFuel);
                    std::cout << "Remaining fuel: " << changedFuel << "\n";
                    break;
                }
                else {
                    std::cout << "Unfortunately, you cannot be able to run away from the space pirates. You encounter with space pirates again.\n";
                    option = chooseOption();
                }
            }
            else {
                std::cout << "You do not have enough fuel. So, you cannot choose to run away.\n";
                std::cout << "Please enter (2) for fighting, and (3) for bargaining.\n";
                std::cin >> option;
                while(!((option == SP_FIGHT) || (option == SP_BARGAIN))) {
                    std::cout << "This is an invalid value. (2) for fighting, and (3) for bargaining.\n";
                    std::cin >> option;
                }
            }
        }
        else if(option == SP_FIGHT) {
            std::cout << "You are going to fight. Good luck.\n";
            escapeProbability = GameManager::generateRandomNumber(2);
            if(escapeProbability == 1) {
                std::cout << "Congrats! You win.\n";
                break;
            }
            else {
                std::cout << "Sorry, you loosed the fight.\n";
                changedHealth -= defaultDamage * chosenShip->getShipCoefficent();
                chosenShip->setHealth(changedHealth);
                std::cout << "Remaining health: " << changedHealth << "\n";
                break;
            }
        }
        else if(option == SP_BARGAIN) {
            std::cout << "You are going to bargain. Good luck.\n";
            double payment = GameManager::generateRandomNumber(3) * 10;
            if(chosenShip->getMoney() >= payment){
                changedMoney -= payment;
                chosenShip->setMoney(changedMoney);
                std::cout << "You pay " << payment << " to space pirates.\n";
                std::cout << "Remaining money: " << changedHealth << "\n";
                break;
            }
            else {
                std::cout << "You do not have enough money to pay. You have to fight.\n";
                option = SP_FIGHT;
            }
        }
    }
    return CONTINUE;
}