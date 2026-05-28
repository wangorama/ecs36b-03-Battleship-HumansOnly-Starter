//
// Created by kingdoofus on 5/18/26.
//

#include "Player.h"

namespace Battleship {
    Player(std::string name, int row, int col, std::vector<std::pair<char, int>> shipTypes);
    virtual ~Player();
    virtual void placeShips() = 0;

    //getter
    Board& getBoard(); //for player attacking the opponent

    const Board& getBoard() const; //to view the boards results after being attacked

    const std::string& getName() const;


}