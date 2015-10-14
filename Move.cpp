//
// Created by nicolas on 03/08/15.
//

#include "Move.h"

Move::Move(Living *livingToMove): movingLiving(livingToMove) {
    path.push_back(livingToMove->getCoordinate());
}

<<<<<<< HEAD
std::vector<Coordinate> Move::getPath() const
{
    return path;
}

void Move::addToPath(const Coordinate nextCoordinate)
{
    path.push_back(nextCoordinate);
}

void Move::setPath(const std::vector<Coordinate> &pathToSet)
{
    path = pathToSet;
}

Living * Move::getLiving() const
{
    return movingLiving;
}
=======
std::vector<Coordinate> Move::getPath() { return path; }

void Move::addToPath(Coordinate nextCoordinate) { path.push_back(nextCoordinate); }

void Move::setPath(std::vector<Coordinate> pathToSet) { path = pathToSet; }

Living * Move::getLiving() { return movingLiving; }
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
