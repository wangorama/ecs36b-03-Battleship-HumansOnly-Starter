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
        Player(std::istream& in, std::ostream& out, std::string name, int row, int col);

        virtual ~Player() = default;

        //getter
        [[nodiscard]] Board& getBoard(); //for player attacking the opponent

        [[nodiscard]] const Board& getBoard() const; //to view the boards results after being attacked

        [[nodiscard]] const std::string& getName() const;


        void set_opponent(Player& opponent);

        //player action
        virtual std::pair<int, int> attack(); //part of the game loop, where they attack

        virtual void placeShips(const std::vector<std::pair<char, int>>& ships);


    private:
        std::string player_name_;
        Board board_;
        Player* opponent_;
        std::istream& in_;
        std::ostream& out_;

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
