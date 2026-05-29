//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
#define ECS36BBATTLESHIPHUMANSONLY_PLAYER_H

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <ranges>
#include "Board.h"
#include <map>

namespace BattleShip {

    class Player {
        public:
        Player(std::istream& in, std::ostream& out, std::string name, int row, int col, std::map<char, int> shipTypes);

        virtual ~Player() = default;

        virtual void placeShips() = 0;

        //getter
        [[nodiscard]] Board& getBoard(); //for player attacking the opponent

        [[nodiscard]] const Board& getBoard() const; //to view the boards results after being attacked

        [[nodiscard]] const std::string& getName() const;

        //setter
        virtual std::pair<int, int> attack() = 0; //part of the game loop, where they attack
        void set_opponent(Player& opponent);


    private:
        std::string player_name_;
        Board board_;
        Player* opponent_;

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
