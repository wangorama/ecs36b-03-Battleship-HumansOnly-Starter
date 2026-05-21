//
// Created by mfbut on 5/3/2026.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_GAME_H
#define ECS36BBATTLESHIPHUMANSONLY_GAME_H
#include <memory>

namespace BattleShip {

class Game {
    /*
    * How we play the game:
    * Players will place their ships, one vertically and one horizontally
    * then each player will have 2 boards, one board reflecting what they hit, the other one is their own board, aka what opponent hit
    * and then the first player to have all their ships in posession sunk will lose
    */
    using PlayerV = std::unique_ptr<Player>; //we use a unique pointer here because this is the one pointer that won't be changed at all
    public:
        explicit BattleShip::Game(const Boards &Boards, Player& Player); //
        bool GameWon() const; //if a player destroys every opponents ships on the board AKA win condition
        void std::pair<int, int> player_attack;


    private:
        std::istream &player_input; //the input of the player's attack and whatever they are going to unput as name or whatever
        std::ostream &result; //what is outputted to show the player's board




};

} // BattleShip

#endif //ECS36BBATTLESHIPHUMANSONLY_GAME_H

