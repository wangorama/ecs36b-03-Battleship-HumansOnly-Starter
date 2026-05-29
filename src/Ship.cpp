//
// Created by kingdoofus on 5/27/26.
//

#include "Ship.h"

#include <ranges>


namespace BattleShip {
    Ship::Ship(char symbol, int size): symbol_(symbol), size_(size), hits_(0) {
        //initializer, aka used as constructor
    }

    void Ship::takeHit() { //every time the ship takes a hit, the hit count increase by 1
        //i.e. health decreases by 1
        hits_++;
    }

    int Ship::getSize() const {
        //ship size
        return size_;
    }

    char Ship::getSymbol() const {
        //symbol representing the ship
        return symbol_;
    }

    bool Ship::isSunk() const {
        return hits_ == size_; //sunk the second the hull is fully destroyed
    }

}
