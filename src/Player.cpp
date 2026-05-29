//
// Created by kingdoofus on 5/18/26.
//

#include "Player.h"



namespace BattleShip {
    Player::Player(std::istream& in, std::ostream& out, std::string name, int row, int col)
    : player_name_(name), board_(row, col, '*', 'X', 'O'), opponent_(nullptr), in_(in), out_(out) {}

    Board& Player::getBoard() {
        return board_;
    }

    const Board& Player::getBoard() const {
        return board_;
    }

    const std::string& Player::getName() const {
        return player_name_;
    }

    void Player::set_opponent(Player& opponent) {
        opponent_ = &opponent;
    }

    std::pair<int, int> Player::attack() {
        int row, col;
        while (true) {
            out_ << player_name_ << "'s Firing Board\n";
            opponent_->getBoard().displayHidden(out_);
            out_ << player_name_ << "'s Placement Board\n";
            board_.display(out_);
            out_ << player_name_ << ", where would you like to fire?\n";
            out_ << "Enter your attack coordinate in the form row col: ";
            in_ >> row >> col;
            if (!opponent_->getBoard().isOnBoard(row, col)) continue;
            if (opponent_->getBoard().hasBeenAttacked(row, col)) continue;
            return {row, col};
        }
    }

    void Player::placeShips(const std::vector<std::pair<char, int>>& ships) {
        std::string orientation;
        int row, col;
        auto sorted_ships = ships;
        std::sort(sorted_ships.begin(), sorted_ships.end());

        for (auto pair : sorted_ships) {
            while (true) {
                board_.display(out_);
                out_ << player_name_ << ", do you want to place " << pair.first << " horizontally or vertically?\n";
                out_ << "Enter h for horizontal or v for vertical\n";
                out_ << "Your choice: ";
                in_ >> orientation;
                if (orientation != "h" && orientation != "H" && orientation != "v" && orientation != "V") {
                    continue;
                }
                out_ << player_name_ << ", enter the row and column you want to place " << pair.first << ", which is " << pair.second << " long, at with a space in between row and col: ";
                in_ >> row >> col;
                Ship ship(pair.first, pair.second);
                bool result = board_.placeShip(row, col, 0, 0, orientation, ship);
                if (result) break;
            }
        }
    }

}
