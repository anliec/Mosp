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
<<<<<<< HEAD
    bool removeLiving(const Living *livingToRemove);
    bool removeLiving(int pos);
    int getPosOnLivings(const Living *livingToRemove) const;
    Object getObject() const;
    std::vector<Living *> getLivings() const;

    Coordinate getCoordinate() const;
    int getType() const;

protected:
=======
    bool removeLiving(Living *livingToRemove);
    bool removeLiving(int pos);
    int getPosOnLivings(Living *livingToRemove) const;
    Object getObject();
    std::vector<Living *> getLivings() const;

    Coordinate getCoordinate();
    int getType();

private:
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
    Coordinate coordinate;
    int type;
    std::vector<Living *> livings;
    Object* object;
};


#endif //MOSP_TILE_H
