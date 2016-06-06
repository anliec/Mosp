#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Map.h"

class World
{
public:
    World(std::vector<std::vector<Map>> map);
    ~World();

protected:
    std::vector<std::vector<Map>> map;
};

#endif // WORLD_H
