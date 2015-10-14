//
// Created by nicolas on 03/08/15.
//

#include "Tile.h"

Tile::Tile(): coordinate(0,0), type(TILE_UNWALKABLE) {
    object = nullptr;
}

Tile::Tile(Coordinate tileCoordinate, int tileType): coordinate(tileCoordinate), type(tileType) {
    object = nullptr;
}

Tile::~Tile() {
    if(object != nullptr){
        delete object;
    }
}

Coordinate Tile::getCoordinate() const { return coordinate; }

/*
 * tri to add objectToAdd to the tile:
 * if the tile is walkable and there are no object on the tile then the object is added to the tile
 * else nothing append
 * return: true if the object was added
 */
bool Tile::addObject(Object objectToAdd) {
    if(type == TILE_WALKABLE && object != nullptr){
        object = new Object(objectToAdd);
        return true;
    }
    else{
        return false;
    }
}

void Tile::addLiving(Living* livingToAdd) {
    livings.push_back(livingToAdd);
    livingToAdd->setCoordinate(coordinate);
}

void Tile::removeObject() {
    delete object;
    object = nullptr;
}

Object Tile::getObject() const { return *object; }

int Tile::getType() const { return type;}

/*
 * remove from the livings list of the tile the case with the same address.
 * if there are no such case, nothing append.
 */
bool Tile::removeLiving(const Living *livingToRemove) {
    return removeLiving(getPosOnLivings(livingToRemove));
}

int Tile::getPosOnLivings(const Living *living) const{
    for (int i = 0; i < livings.size(); ++i) {
        if(livings.at(i) == living){
            return i; //end the 'for' once one living is found.
        }
    }
    return -1;
}

bool Tile::removeLiving(int pos) {
    if(pos >= 0 && pos < livings.size()){
        livings.erase(livings.begin()+pos);
        return true;
    }
    else{
        return false;
    }
}

std::vector<Living *> Tile::getLivings() const{
    return livings;
}
