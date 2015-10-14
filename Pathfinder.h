//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_PATHFINDER_H
#define MOSP_PATHFINDER_H

#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Map.h"

class Pathfinder {
public:
<<<<<<< HEAD
    Pathfinder(Coordinate from, Coordinate to, Map sourceMap, int deapLimit = 40);
=======
    Pathfinder(Coordinate from, Coordinate to, Map sourceMap, int deapLimit = 20);
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade

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
<<<<<<< HEAD
=======
    std::vector<Coordinate> exploredTiles;
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
    bool computed;
    int minDeep;
    int currantDeep;
    int maxDeep;
    std::vector<Coordinate> direction;
};


#endif //MOSP_PATHFINDER_H
