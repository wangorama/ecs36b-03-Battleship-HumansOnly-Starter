//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
#define ECS36BBATTLESHIPHUMANSONLY_PLAYER_H

#include <vector>
#include <memory>

namespace BattleShip {
    using PlayerVector = std::vector<std::unique_ptr<Player>>; // we use a unique pointer to represent a player
    using ShipVector = std::vector<std::pair<char, int>>; //this is to mark the name of the ship(s)

    class Player {
        public:
            virtual void ObtainConfiguration(int &row, int &col, int &ship) const; //rows, columns and ships thatll be there
            virtual void Attack(int& row, int& col) const; //why do i need to get the configuration form a player
            virtual void PlaceShip(int& row, int& col);

        private:

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
