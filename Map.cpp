//
// Created by nicolas on 03/08/15.
//

#include "Map.h"

Map::Map() { }

Map::Map(int height, int width)
{
    std::vector<Tile> column;

    for(int i=0 ; i<height ; i++){
        column.push_back(Tile());
    }

    for (int j = 0; j < width; ++j) {
        tiles.push_back(column);
    }
}

Map::Map(std::string filePath)
{
    try{
        std::ifstream myStream(filePath);

        if(myStream)
        {
            char c;
            int line = 0;
            int i=0;
            while(myStream.get(c))
            {
                if(c != '\n')
                {
                    if(i >= tiles.size())
                    { //if the column doesn't exist
                        std::vector<Tile> column;
                        tiles.push_back(column); //add the column
                        //add the missing lines:
                        for (int y = 0; y < line; ++y)
                        {
                            tiles.at(i).push_back(Tile(Coordinate(i,line),TILE_UNWALKABLE));
                        }
                    }
                    int type;
                    if(std::isdigit(c))
                    {
                        type = std::atoi(&c);
                    }
                    else
                    {
                        type = TILE_UNWALKABLE;
                    }
                    tiles.at(i).push_back( Tile(Coordinate(i,line),type));
                    i++;
                }
                else
                {
                    i=0;
                    line++;
                }
            }
        }
        else
        {
            std::cerr << "ERROR WHEN LOADING FILE: " << filePath << std::endl;
        }
        myStream.close();
    }
    catch(std::exception const& e)
    {
        std::cerr << "ERROR WHEN LOADING FILE: " << filePath << std::endl << e.what() << std::endl;
        throw;
    }

}

void Map::printMap() const
{
    int y=0;
    bool lineLeft = true;

    while(lineLeft){
        lineLeft = false;
        for (int x = 0; x < tiles.size(); ++x) {
            try {
                std::cout << tiles.at(x).at(y).getType();
                lineLeft = true; //if there are at least one tile on that line it can be usefull to read the next one
            }
            catch(std::exception const& e){
                //nothing to do...
            }
        }
        std::cout << std::endl;
        y++;
    }
}

Tile & Map::getTile(Coordinate c)
{
    try
    {
        return tiles.at(c.getX()).at(c.getY());//return a reference to the tile
    }
    catch(std::exception & e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        throw;
    }
}

bool Map::applyMove(Move move)
{ //return the number of small move done ?
    std::vector<Coordinate> path = move.getPath();
    Coordinate last = path.front();
    for (int i = 1; i < path.size(); ++i) {
        if(!smallMove(move.getLiving(),last,path.at(i))){
            return false;//if one move fail stop the entire move.
        }
        last = path.at(i);
    }
    return true;
}

bool Map::smallMove(Living *livingToMove, Coordinate from, Coordinate to)
{
    if(norm1(from,to)==1){
        /*Tile & beginning = getTile(from);
        Tile & ending = getTile(to);*/
        if(getTile(to).getType() != TILE_WALKABLE){
            std::cout << "tile not walkable" << std::endl;
            return false;
        }
        if(getTile(from).removeLiving(livingToMove)){
            getTile(to).addLiving(livingToMove);
            return true;
        }
        else{
            std::cout << "living does not existe on " << from << std::endl;
            return false;
        }
    }
    else{
        return false;
    }
}

bool Map::isOnMap(const Coordinate c) const
{

    if(tiles.size() > c.getX()){
        if(tiles.at(c.getX()).size() > c.getY()){
            return true;
        }
    }
    return false;
}

int Map::getHeight() const
{
    int maxHeight=0;
    for(int i=0 ; i<tiles.size() ; i++){
        if(tiles.at(i).size() > maxHeight){
            maxHeight = tiles.at(i).size();
        }
    }
    return maxHeight;
}

int Map::getWidth() const
{
    return tiles.size();
}

Tile & Map::at(const Coordinate & coord)
{
    if(isOnMap(coord)){
        return tiles.at(coord.getX()).at(coord.getY()); //return a reference to the tile
    }
    else{
        Tile tile(coord, TILE_UNWALKABLE);
        return tile;
    }
}

Tile Map::readTileAt(const Coordinate & coord) const
{
    if(isOnMap(coord)){
        return tiles.at(coord.getX()).at(coord.getY()); //return a reference to the tile
    }
    else{
        return Tile(coord, TILE_UNWALKABLE);
    }
}

void Map::addLiving(Living * living){
    at(living->getCoordinate()).addLiving(living);
}




