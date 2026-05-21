//
// Created by kingdoofus on 5/21/26.
//

#include "BoardCell.h"

namespace BattleShip {
    BoardCell::BoardCell() : ship_component(), square_attacked(false); //declare constructor as clean slate

    bool square_attacked() const { return square_attacked; }

}