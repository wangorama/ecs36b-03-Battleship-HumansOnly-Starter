//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
#define ECS36BBATTLESHIPHUMANSONLY_PLAYER_H

#include <vector>
#include
#include <memory>

namespace BattleShip {
    using PlayerVector = std::vector<std::unique_ptr<Player>>; // we use a unique pointer to represent a player
    using ShipVector = std::vector<std::pair<char, int>>; //

    class Player {

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_PLAYER_H
