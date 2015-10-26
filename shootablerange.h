#ifndef SHOOTABLERANGE_H
#define SHOOTABLERANGE_H

#include "Map.h"

class ShootableRange : public range
{
public:
    ShootableRange(const Map &map,const Coordinate centerPos, int type =0, int maxRange =0, int minRange =0);
    std::vector<std::vector<byte>> getShootableTiles();

private :
    void computeTile(const Map &map, const Coordinate crd);
    byte bresenham(const Coordinate crd);
    Coordinate switchToOctantZeroFrom(byte octant, Coordinate crd);
    Coordinate switchFromOctantZeroTo(byte octant, Coordinate crd);

    std::vector<std::vector<byte>> m_shootableTiles;
    Coordinate m_absolutePosOnMap;
    byte m_center;
};

#endif // SHOOTABLERANGE_H
