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

<<<<<<< HEAD
    void addToPath(const Coordinate nextCoordinate);
    std::vector<Coordinate> getPath() const;
    void setPath(const std::vector<Coordinate> &pathToSet);
    Living * getLiving() const;
=======
    void addToPath(Coordinate nextCoordinate);
    std::vector<Coordinate> getPath();
    void setPath(std::vector<Coordinate> pathToSet);
    Living * getLiving();
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade

private:
    std::vector<Coordinate> path;
    Living * movingLiving;
};


#endif //MOSP_MOVE_H
