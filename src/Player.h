//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
#define ECS36BBATTLESHIPHUMANSONLY_PLAYER_H

#include <vector>
#include <memory>
#include <iostream>
#include "Board.h"

namespace BattleShip {

    class Player {
        public:
        Player(std::string name, int row, int col, std::vector<std::pair<char, int>> shipTypes);
        virtual ~Player();
        virtual void placeShips() = 0;

        //getter
        [[nodiscard]] Board& getBoard(); //for player attacking the opponent

        [[nodiscard]] const Board& getBoard() const; //to view the boards results after being attacked

        [[nodiscard]] const std::string& getName() const;

        virtual std::pair<int, int> attack() = 0; //part of the game loop, where they attack


    private:
        std::string player_name_;
        Board board_;

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
