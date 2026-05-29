//
// Created by kingdoofus on 5/18/26.
//

#include "Player.h"



namespace Battleship {

    


    virtual void placeShips() {

    }

    //getter
    BattleShip::Board& getBoard(); //for player attacking the opponent

    const BattleShip::Board& getBoard() const; //to view the boards results after being attacked

    const std::string& getName() const;

    void BattleShip::Player::set_opponent(Player& opponent) {

    }


}
