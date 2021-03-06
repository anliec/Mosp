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

    void printMap() const;
    bool applyMove(const Move move);
    bool smallMove(Living * livingToMove,Coordinate from, Coordinate to);
    bool isOnMap(const Coordinate) const;

    Tile *at(const Coordinate &coordinate);
    Tile readTileAt(const Coordinate &coordinate) const;
    void addLiving(Living *living);

    int getWidth() const;
    int getHeight() const;

private:
    std::vector< std::vector<Tile> > tiles;
    std::vector<Coordinate> team1Tiles; //unused
    std::vector<Coordinate> team2Tiles; //unused
};


#endif //MOSP_MAP_H
