#ifndef SHOOTABLERANGE_H
#define SHOOTABLERANGE_H

#include "Map.h"
#include <math.h>

class ShootableRange : public range
{
public:
    ShootableRange(const Map &map,const Coordinate centerPos, int type =0, int maxRange =0, int minRange =0);
    std::vector<std::vector<unsigned char>> getShootableTiles();

private :
    void computeTile(const Map &map, const Coordinate crd);
    unsigned char bresenhamCheck(const Coordinate crd);

    std::vector<std::vector<unsigned char>> m_shootableTiles;
    Coordinate m_absolutePosOnMap;
    unsigned char m_center;
};

#endif // SHOOTABLERANGE_H
