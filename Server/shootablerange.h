#ifndef SHOOTABLERANGE_H
#define SHOOTABLERANGE_H

#include "core/world/Map.h"
#include <math.h>
#include <vector>

class ShootableRange
{
public:
    ShootableRange(const Map &map, const Coordinate &centerPos, int maxRange =0, int minRange =0);
    std::vector<std::vector<unsigned char>> getShootableTiles();

private :
    void computeTile(const Map &map, const Coordinate &crd, const Coordinate &upLeftCrd);
    unsigned char bresenhamCheck(const Coordinate crd);

    std::vector<std::vector<unsigned char>> m_shootableTiles;
    Coordinate m_absolutePosOnMap;
    unsigned char m_center;

    unsigned int m_maxRange;
    unsigned int m_minRange;
};

#endif // SHOOTABLERANGE_H
