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

    std::vector<std::vector<byte>> m_shootableTiles;
    m_centerPos;
};

#endif // SHOOTABLERANGE_H
