//
// Created by nicolas on 03/08/15.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(Coordinate from, Coordinate to, Map sourceMap, int deapLimit): beginning(from), ending(to), map(sourceMap),maxDeep(deapLimit){
    computed = false;
}

std::vector<Coordinate> Pathfinder::compute() {
    //if the beginning and the end are the same:
    if(beginning == ending){
        path.push_back(ending);
        return path;
    }
    //if the destination is not walkable:
    if(map.getTile(ending).getType() != TILE_WALKABLE){
        path.clear();
        return path;
    }


    minDeep = norm1(beginning,ending);

    direction.resize(4,Coordinate(0,0));
    if(beginning.getX() > ending.getX())
    {
        direction[0] = Coordinate(-1,0);
        direction[2] = Coordinate(1,0);
    }
    else
    {
        direction[2] = Coordinate(-1,0);
        direction[0] = Coordinate(1,0);
    }

    if(beginning.getY() > ending.getY())
    {
        direction[1] = Coordinate(0,-1);
        direction[3] = Coordinate(0,1);
    }
    else
    {
        direction[3] = Coordinate(0,-1);
        direction[1] = Coordinate(0,1);
    }

    for (currantDeep=minDeep; currantDeep < maxDeep; currantDeep++)
    {
        path.push_back(beginning);
        //std::cout << "triing for deap: " << currantDeep << std::endl;
        if(explore())
        {
            return path;
        }
        path.clear();
    }
    //if nothing found before maxDeap:
    path.empty();
    return path;
}

bool Pathfinder::explore() {
    for (int i = 0; i < 4; i++) {
        path.push_back(path.back() + direction[i]);
        if(path.back() == ending){
            return true;
        }
        else if(onCurrantPath(path.back())){

        }
        else if(path.size() >= currantDeep){
            //if the path is longer than the longer path we are looking for: this tile is not the good one
        }
        else if(norm1(path.back(),ending) > currantDeep-path.size()) {
            //if the destination can't be reach in with the deep left
        }
        else if(!map.isOnMap(path.back())){
            //check that the tile is on the map
        }
        else if(map.getTile(path.back()).getType() != TILE_WALKABLE){//the tile is now on the map
            //if the tile can't be used
        }
        else{ //if there no reason not to tri to find a way by this tile, we tri
            if(explore()){
                return true;
            }
        }

        path.pop_back();
    }
    return false;
}

/*
 * look if the given coordinate are on the current path excluding the last value.
 */
bool Pathfinder::onCurrantPath(Coordinate c) {
    for (int i = 0; i < path.size()-1; i++) {
        if(path.at(i) == c){
            return true;
        }
    }
    return false;
}
