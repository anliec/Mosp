//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_PATHFINDER_H
#define MOSP_PATHFINDER_H

#include <iostream>
#include <vector>
#include "core/world/Coordinate.h"
#include "core/world/Map.h"

class Pathfinder {
public:
    Pathfinder(Coordinate from, Coordinate to, Map sourceMap, int deapLimit = 40);

    std::vector<Coordinate> compute();

protected:
    bool explore();
    bool alreadyExplored(Coordinate c);
    bool onCurrantPath(Coordinate c);

private:
    Coordinate beginning;
    Coordinate ending;
    Map map;
    std::vector<Coordinate> path;
    bool computed;
    int minDeep;
    int currantDeep;
    int maxDeep;
    std::vector<Coordinate> direction;
};


#endif //MOSP_PATHFINDER_H
