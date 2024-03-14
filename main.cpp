#include <iostream>
#include "SpaceShip.h"
#include "GameEvent.h"
#include "GameManager.h"

int main() {
    srand(time(0));
    GameManager gameManager;
    gameManager.initializeGameManager();
    return 0;
}
