//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_BOARD_H
#define ECS36BBATTLESHIPHUMANSONLY_BOARD_H
#include "Player.h"

namespace BattleShip {
    class Board {
        public:
            void FiringBoard(int row, int col); //the players firing board
            void PlacementBoard(int row, int col ); //the placement of the board

        private:

    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_BOARD_H
