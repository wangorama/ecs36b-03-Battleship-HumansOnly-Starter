//
// Created by mfbut on 5/3/2026.
//

#include "Game.h"

#include <fstream>

namespace BattleShip {
    Game::Game(const std::string& configFile) {
        std::ifstream file(configFile);
        int num_ships;
        file >> num_rows_ >> num_cols_ >> num_ships;
        for (int i = 0; i < num_ships; i++) {
            char symbol;
            int size;
            file >> symbol >> size;
            ships_.push_back({symbol, size});
        }
    }

    void Game::setUp() {
        std::cout << "Player 1 please enter your name: ";
        std::string name1;
        std::getline(std::cin, name1);
        player1 = std::make_unique<Player>(std::cin, std::cout, name1, num_rows_, num_cols_);
        std::cout << "Player 2 please enter your name: ";
        std::string name2;
        std::getline(std::cin, name2);
        player2 = std::make_unique<Player>(std::cin, std::cout, name2, num_rows_, num_cols_);
        player1->set_opponent(*player2);
        player2->set_opponent(*player1);
        player1->placeShips(ships_);
        player2->placeShips(ships_);
    }

    void Game::play() {
        setUp();
        while (!isOver()) {
            takeTurn(*player1, *player2);
            if (isOver()) break;
            takeTurn(*player2, *player1);
        }
        if (player1->getBoard().allShipsSunk()) {
            std::cout << player2->getName() << " won the game!\n";
        } else {
            std::cout << player1->getName() << " won the game!\n";
        }
    }

    void Game::takeTurn(Player& shooter, Player& target) {
        auto [row, col] = shooter.attack();
        char symbol = target.getBoard().getShipSymbol(row, col);
        Board::Attack_Result result = target.getBoard().receiveShot(row, col);

        if (result == Board::Attack_Result::Miss) {
            std::cout << "Missed.\n";
        } else if (result == Board::Attack_Result::Hit) {
            std::cout << shooter.getName() << " hit " << target.getName() << "'s " << symbol << "!\n";
        } else if (result == Board::Attack_Result::Sunk) {
            std::cout << shooter.getName() << " hit " << target.getName() << "'s " << symbol << "!\n";
            std::cout << shooter.getName() << " destroyed " << target.getName() << "'s " << symbol << "!\n";
        }
    }

    bool Game::isOver() const {
        return player1->getBoard().allShipsSunk() || player2->getBoard().allShipsSunk();
    }

} // BattleShip