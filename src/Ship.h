//
// Created by kingdoofus on 5/27/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_SHIP_H
#define ECS36BBATTLESHIPHUMANSONLY_SHIP_H


namespace BattleShip{
class Ship {
    public:
    Ship(char symbol, int size);
    void takeHit();
    bool isSunk() const;

private:
    char symbol_;
    int size_;
    int hits_;

};
}


#endif //ECS36BBATTLESHIPHUMANSONLY_SHIP_H
