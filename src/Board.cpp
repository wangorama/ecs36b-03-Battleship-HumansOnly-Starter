//
// Created by kingdoofus on 5/18/26.
//

#include "Board.h"

#include <algorithm>

namespace BattleShip {
    Board::Board(const int num_rows, const int num_cols,
                             char blank_char,
                             char hit_marker,
                             char miss_marker) : num_rows_(num_rows), num_cols_(num_cols),
    blank_char_(blank_char), hit_marker_(hit_marker), miss_marker_(miss_marker),
    grid_(num_rows, std::vector<BoardCell>(num_cols)) {}

    void Board::display(std::ostream& out) const {

        out << ' ';
        for (int col = 0; col < num_cols_; col++) {
            out << col + 1 << ' ';
        }
        out << '\n';

        for (int row = 0; row < num_rows_; row++) {

            out << row + 1 << ' ';  // print row number

            for (int col = 0; col < num_cols_; col++) {

                if (grid_[row][col].contains_ship()) {

                    if (grid_[row][col].has_been_attacked()) {
                        out << hit_marker_ << ' ';
                    } else {
                        out << grid_[row][col].get_ship_symbol()<< ' ';
                    }
                }
                else {
                    if (grid_[row][col].has_been_attacked()) {
                        out<<miss_marker_ << ' ';
                    }
                    else {
                        out<<blank_char_ << ' ';
                    }
                }
            }
            out << '\n';
        }
    }

    void Board::displayHidden(std::ostream& out) const {
        //opponent's board, so won't show their ship at all

        out << ' ';
        for (int col = 0; col < num_cols_; col++) {
            out << col + 1 << ' ';
        }
        out << '\n';

        for (int row = 0; row < num_rows_; row++) {

            out << row + 1 << ' ';  // print row number

            for (int col = 0; col < num_cols_; col++) {
                if (grid_[row][col].contains_ship()) {
                    if (grid_[row][col].has_been_attacked()) {
                        out<<hit_marker_ << ' ';
                    }
                    else {
                        out<< blank_char_ << ' ';
                    }
                }
                else {
                    out<<blank_char_ << ' ';
                }
            }
            out << '\n';

        }

    }


    bool Board::placeShip(const int start_row, const int start_col, int end_row, int end_col, const std::string& orientation, const Ship& ship) {


        if (orientation == "h") {
            end_col = start_col + ship.getSize() - 1;
            if (end_col > num_cols_ - 1 || start_col < 0) return false;
            for (int col = start_col; col <= end_col; col++) {
                if (grid_[start_row][col].contains_ship()) return false;
                grid_[start_row][col].add_ship(ship.getSymbol());
            }
            ships_.push_back(ship);

        } else if (orientation == "v") {
            end_row = start_row + ship.getSize() - 1;
            if (end_row > num_rows_ - 1 || start_row < 0) return false;
            for (int row = start_row; row <= end_row; row++) {
                if (grid_[row][start_col].contains_ship()) return false;
                grid_[row][start_col].add_ship(ship.getSymbol());
            }
            ships_.push_back(ship);
        }

        return true;
    }

    Board::Attack_Result Board::receiveShot(const int row, const int col) {
        char symbol = grid_[row][col].get_ship_symbol();
        grid_[row][col].mark_as_attacked();
        if (grid_[row][col].contains_ship()) {
            for (auto& ship : ships_) {
                if (ship.getSymbol() == symbol) {
                    ship.takeHit();
                    if (ship.isSunk()) return Attack_Result::Sunk;
                    return Attack_Result::Hit;
                }
            }
        } 

        return Attack_Result::Miss;
    }

    bool Board::allShipsSunk() const {
        for (auto ship : ships_) if (!ship.isSunk()) return false;

        return true;
    }
}
