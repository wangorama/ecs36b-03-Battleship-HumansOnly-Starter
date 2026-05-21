//
// Created by kingdoofus on 5/18/26.
//

#ifndef ECS36BBATTLESHIPHUMANSONLY_SHIP_H
#define ECS36BBATTLESHIPHUMANSONLY_SHIP_H


namespace Battleship {
    /*
     * this ship class, includes elements of
     * the ship placement
     * and their get hit stats or sunk
     */
    class Ship {
        public:
            //the coordinates the ship occupies. starting rows and columns is the first coordinate
            //and it extends to the end rows and columns
            Ship(char ship_name, int start_row, int start_col, int end_row, int end_col);

            //getters, or data of each individual ship
            


        private:



    };
}

#endif //ECS36BBATTLESHIPHUMANSONLY_SHIP_H
