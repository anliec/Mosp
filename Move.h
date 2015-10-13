//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_MOVE_H
#define MOSP_MOVE_H


#include "Living.h"
#include <iostream>
#include <vector>

class Move {
public:
    Move(Living * livingToMove);

    void addToPath(Coordinate nextCoordinate);
    std::vector<Coordinate> getPath();
    void setPath(std::vector<Coordinate> pathToSet);
    Living * getLiving();

private:
    std::vector<Coordinate> path;
    Living * movingLiving;
};


#endif //MOSP_MOVE_H
