//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_MOVE_H
#define MOSP_MOVE_H


#include "core/living/Living.h"
#include <iostream>
#include <vector>

class Move {
public:
    Move(Living * livingToMove);

    void addToPath(const Coordinate nextCoordinate);
    std::vector<Coordinate> getPath() const;
    void setPath(const std::vector<Coordinate> &pathToSet);
    Living * getLiving() const;

private:
    std::vector<Coordinate> path;
    Living * movingLiving;
};


#endif //MOSP_MOVE_H
