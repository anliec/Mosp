//
// Created by nicolas on 03/08/15.
//
#include <iostream>
#include <vector>
#include "Coordinate.h"
#include "Living.h"
#include "Object.h"

#ifndef MOSP_TILE_H
#define MOSP_TILE_H

#define TILE_WALKABLE 0
#define TILE_UNWALKABLE 1
#define TILE_VIEW_BLOCKING 2


class Tile {
public:
    Tile();
    Tile(Coordinate tileCoordinates, int tileType = TILE_WALKABLE);
    ~Tile();

    bool addObject(Object objectToAdd);
    void addLiving(Living *livingToAdd);
    void removeObject();
    bool removeLiving(const Living *livingToRemove);
    bool removeLiving(int pos);
    int getPosOnLivings(const Living *livingToRemove) const;
    Object getObject() const;
    std::vector<Living *> getLivings() const;

    Coordinate getCoordinate() const;
    int getType() const;

private:
    Coordinate coordinate;
    int type;
    std::vector<Living *> livings;
    Object* object;
};


#endif //MOSP_TILE_H
