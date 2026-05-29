//
// Created by mfbut on 5/3/2026.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_GAME_H
#define ECS36BBATTLESHIPHUMANSONLY_GAME_H
#include <memory>

#include "Player.h"

namespace BattleShip {

class Game {
    /*
    * How we play the game:
    * Players will place their ships, one vertically and one horizontally
    * then each player will have 2 boards, one board reflecting what they hit, the other one is their own board, aka what opponent hit
    * and then the first player to have all their ships in posession sunk will lose
    */

    public:
        Game(const std::string& configFile);

        void play();


    private:
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        std::vector<std::pair<char, int>> ships_;
        int num_rows_;
        int num_cols_;
        void setUp();
        void takeTurn(Player& shooter, Player& target);
        bool isOver() const;



};

} // BattleShip

#endif //ECS36BBATTLESHIPHUMANSONLY_GAME_H

