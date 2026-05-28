//
// Created by kingdoofus on 5/21/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
#define ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
#include <optional>
#include <vector>

#include "Ship.h"

namespace BattleShip {
    /* This represents each individual statistics of each board cell
     * I like to think of this just as a mailbox itself, and Board is the houses
     * storing the mailbox
     */

    class BoardCell {
    public:
        BoardCell();

        //getters
        [[nodiscard]] bool contains_ship() const;
        [[nodiscard]] bool has_been_attacked() const;
        [[nodiscard]] char get_ship_symbol() const;

        //setters
        void add_ship(char ship); //action of adding a ship to make it contain a ship
        void mark_as_attacked();

    private:
        bool has_been_attacked_;
        std::optional<char> ship_;

    };
}

#endif //ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
