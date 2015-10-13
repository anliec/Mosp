//
// Created by nicolas on 03/08/15.
//

#include "Move.h"

Move::Move(Living *livingToMove): movingLiving(livingToMove) {
    path.push_back(livingToMove->getCoordinate());
}

std::vector<Coordinate> Move::getPath() { return path; }

void Move::addToPath(Coordinate nextCoordinate) { path.push_back(nextCoordinate); }

void Move::setPath(std::vector<Coordinate> pathToSet) { path = pathToSet; }

Living * Move::getLiving() { return movingLiving; }