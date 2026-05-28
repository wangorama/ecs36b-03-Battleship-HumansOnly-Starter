//
// Created by kingdoofus on 5/18/26.
//

#include "Board.h"
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

    bool Board::placeShip(const int start_row, const int start_col, const std::string& orientation, const Ship& ship) {



    }

    Board::Attack_Result Board::receiveShot(const int row, const int col) {

    }

    bool Board::allShipsSunk() const {

    }
}