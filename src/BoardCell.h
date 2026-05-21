//
// Created by kingdoofus on 5/21/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
#define ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
#include <optional>

namespace BattleShip {
    /* This represents each individual statistics of each board cell */
    class BoardCell {
    public:
        BoardCell();

        //these need the [[nodiscard]] because there is a dedicated purpose, and only one purpose of the functoin
        //returning the specified value. otherwise, the side effects of it just staying, instead of a compiler
        //writing errors over the function not being used, can cause unknown gmae bugs like misfirings

        [[nodiscard]] bool square_attacked() const; //marks to see if the square was hit or not

        [[nodiscard]] bool ship_component_occupies() const; //occupes a ship

        [[nodiscard]] std::optional<char> ship() const;

        //these are fine without the nodiscards because

        void set_square_attacked();

        void add_ship(char ship);

    private:
        std::optional<char> ship_component;
        bool square_attacked_;

    };
}

#endif //ECS36BBATTLESHIPHUMANSONLY_BOARDCELL_H
