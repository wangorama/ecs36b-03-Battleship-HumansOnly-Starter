//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_BOARD_H
#define ECS36BBATTLESHIPHUMANSONLY_BOARD_H
#include "BoardCell.h"
#include <vector>
#include "Ship.h"
#include <string>
#include <ostream>

namespace BattleShip {
    class Board {
        public:
            enum class Attack_Result { Miss, Hit, Sunk }; //only 3 status needed, so thats why an enum class is created

            Board(const int num_rows, const int num_cols,
            const char blank_char = '*',
            const char hit_marker = 'X',
            const char miss_marker = 'O'); //board constructor of whats universally available for now, ie, both your firing board
            Board(int num_rows, int num_cols, int blank_char, int hit_marker, int miss_marker); //the health of your board

            void display(std::ostream& out) const; //for your board, where you get to see your ships
            void displayHidden(std::ostream& out) const; //for seeing your opponents board

            bool placeShip(const int start_row, const int start_col, int end_row, int end_col, const std::string& orientation, const Ship& ship);
            Attack_Result receiveShot(const int row, const int col);
            bool allShipsSunk() const;


        private:
            int num_rows_;
            int num_cols_;
            char blank_char_, hit_marker_, miss_marker_;
            std::vector<Ship> ships_;
            std::vector<std::vector<BoardCell>> grid_;


    };
}


#endif //ECS36BBATTLESHIPHUMANSONLY_BOARD_H
