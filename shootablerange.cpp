#include "shootablerange.h"

ShootableRange::ShootableRange(const Map &map,const Coordinate centerPos, int type =0, int maxRange =0, int minRange =0) :
    m_absolutePosOnMap(centerPos), Range(type, maxRange, minRange)
{
    m_shootableTiles = new vector<vector<unsigned char>>;
    for(unsigned char i=0; i<2*maxRange+1; i++)
    {
        vector<unsigned char> column;
        m_shootableTiles.push_back(column);
        for(byte j=0; j<2*radius+1; j++)
        {
            m_shootableTiles.at(i).push_back(0);
        }
    }
    unsigned char m_center = m_shootableTiles.size()/2;
    Coordinate upLeftCrd(m_absolutePosOnMap-maxRange, m_absolutePosOnMap-maxRange);
    for (unsigned char radius=minRange; radius<=maxRange; ++radius)
    {
        for (unsigned char i=m_center; i<=m_center+radius; i++)
        {
            computeTile(map, Coordinate(2*m_center-i,-radius+1));
            computeTile(map, Coordinate(2*m_center-i,2*m_center+radius-i));
            computeTile(map, Coordinate(i,-radius+i));
            computeTile(map, Coordinate(i,2*m_center+radius-i));
        }
    }//at this point, all the view blocking tiles in the range are found. Now we must find where we cannot shoot
}

void ShootableRange::computeTile(const Map &map, const Coordinate crd, const Coordinate upLeftCrd)
{
    Coordinate mapCrd = crd;
    mapCrd.setX(mapCrd.getX()+ upLeftCrd.getX());
    mapCrd.setY(mapCrd.getY()+ upLeftCrd.getY());
    if(map.at(mapCrd).getObject()!=nullptr && map.at(mapCrd).getLivings()!=nullptr)
    {
        m_shootableTiles.at(crd.getX()).at(crd.getY())=TILE_VIEW_BLOCKING;
    }

    m_shootableTiles.at(crd.getX()).at(crd.getY()) = bresenham(crd)
}

unsigned char ShootableRange::bresenham(const Coordinate crd)
{
    Coordinate octantZeroCrd;
    if(crd.getX()==m_center)
    {

    }
    else if(crd.getY()==m_center)
    {

    }
    else
    {
        unsigned char octant;
        dYdX = (crd.getY()-m_center)/(crd.getX()-m_center);
        if(dYdX >0)
        {

        }
    }
}

Coordinate ShootableRange::switchToOctantZeroFrom(byte octant, Coordinate crd)
{
    switch(octant)
    {
    case 0:
        return Coordinate;
    case 1 :
    case 2 :
    case 3 :
    case 4 :
    case 5 :
    case 6 :
    case 7 :
    }
}

Coordinate ShootableRange::switchFromOctantZeroTo(octant, Coordinate crd)
{
    switch(octant)
    {
    case 0:
        ;
    case 1 :
    case 2 :
    case 3 :
    case 4 :
    case 5 :
    case 6 :
    case 7 :
    }
}

/* radius 3 et radius 2 sur maxRange 3 et minRange 2
0001000 0000000
0010100 0001000
0100010 0010100
1000001 0100010
0100010 0010100
0010100 0001000
0001000 0000000

i=1 j=3 center =3 radius =2
i=2 j=2 & 4 center = 3 radius =2
i=3 j=1 & 5 center = 3 radius =2
i=4 j=2 & 4 center = 3 radius =2
i=5 j=3 center = 3 radius =2
*/
