//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_MAP_H
#define MOSP_MAP_H


#include <iostream>
#include <vector>
#include <iosfwd>
#include <fstream>
#include "Tile.h"
#include "Move.h"

class Map {
public:
    Map();
    Map(int height, int width);
    Map(std::string filePath);

    Tile & getTile(Coordinate);

    void printMap();
    bool applyMove(Move move);
    bool smallMove(Living * livingToMove,Coordinate from, Coordinate to);
    bool isOnMap(Coordinate);

private:
    std::vector< std::vector<Tile> > tiles;
};


#endif //MOSP_MAP_H
