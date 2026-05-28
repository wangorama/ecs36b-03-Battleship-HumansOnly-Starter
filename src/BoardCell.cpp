//
// Created by kingdoofus on 5/21/26.
//

#include "BoardCell.h"

namespace BattleShip {
    BoardCell::BoardCell(): has_been_attacked_(false) {}


    bool BoardCell::contains_ship() const {
        return ship_.has_value();
    }

    bool BoardCell::has_been_attacked() const {
        return has_been_attacked_;
    }

    char BoardCell::get_ship_symbol() const {
        if (ship_.has_value()) {
            return ship_.value();
        }
        return ' ';
    }


    void BoardCell::add_ship(char ship) {
        //action of adding a ship to make it contain a ship
        ship_.emplace(ship);
    }

    void BoardCell::mark_as_attacked() {
        has_been_attacked_ = true;
    }

}