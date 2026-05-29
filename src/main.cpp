#include <iostream>

#include "Game.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./BattleShipExe PathToConfigFile\n";
        return 1;
    }
    BattleShip::Game game(argv[1]);
    game.play();
    return 0;
}
