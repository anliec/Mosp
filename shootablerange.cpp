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
    else
    {
        m_shootableTiles.at(crd.getX()).at(crd.getY()) = bresenhamCheck(crd);
    }
}

unsigned char ShootableRange::bresenhamCheck(const Coordinate crd)
{
    unsigned char x0=m_center, y0=m_center;
    unsigned char x1=crd.getX(), y1=crd.getY();

    bool swapXY = abs(y1 - y0) > abs(x1 - x0);
    if (swapXY) {
        // swap x and y
        unsigned char tmp = x0; x0 = y0; y0 = tmp; // swap x0 and y0
        tmp = x1; x1 = y1; y1 = tmp; // swap x1 and y1
    }

    if ( x0 > x1 ) {
        // make sure x0 < x1
        unsigned char tmp = x0; x0 = x1; x1 = tmp; // swap x0 and x1
        tmp = y0; y0 = y1; y1 = tmp; // swap y0 and y1
    }

    signed char deltaX = x1 - x0;
    signed char deltaY = floor( abs( y1 - y0 ) );
    signed char error = floor( deltax / 2 );
    signed char y = y0;
    signed char yStep =(y0 < y1) ? 1 : -1;

    if(swapXY)
        // Y / X
        for ( x=0; x<=x1; x++) {
            if( /*!rayCanPass(y,x)*/m_shootableTiles.at(y).at(x)==TILE_VIEW_BLOCKING )
                return TILE_UNTARGETABLE;

            error -= deltaY;
            if ( error < 0 ) {
                y = y + yStep;
                error = error + deltaX;
            }
        }
    else
        // X / Y
        for (x=0; x<=x1; x++) {
            if( /*!rayCanPass(x,y)*/m_shootableTiles.at(x).at(y)==TILE_VIEW_BLOCKING )
                return TILE_UNTARGETABLE;

            error -= deltaY;
            if ( error < 0 ) {
                y = y + yStep;
                error = error + deltaX;
            }
        }
    return true;
}

/*function checkLine(x0:Int, y0:Int, x1:Int, y1:Int, rayCanPass:Int->Int->Bool) {
    var swapXY = fastAbs( y1 - y0 ) > fastAbs( x1 - x0 );
    var tmp : Int;
    if ( swapXY ) {
        // swap x and y
        tmp = x0; x0 = y0; y0 = tmp; // swap x0 and y0
        tmp = x1; x1 = y1; y1 = tmp; // swap x1 and y1
    }

    if ( x0 > x1 ) {
        // make sure x0 < x1
        tmp = x0; x0 = x1; x1 = tmp; // swap x0 and x1
        tmp = y0; y0 = y1; y1 = tmp; // swap y0 and y1
    }

    var deltax = x1 - x0;
    var deltay = fastFloor( fastAbs( y1 - y0 ) );
    var error = fastFloor( deltax / 2 );
    var y = y0;
    var ystep = if ( y0 < y1 ) 1 else -1;

    if( swapXY )
        // Y / X
        for ( x in x0 ... x1+1 ) {
            if( !rayCanPass(y,x) )
                return false;

            error -= deltay;
            if ( error < 0 ) {
                y = y + ystep;
                error = error + deltax;
            }
        }
    else
        // X / Y
        for ( x in x0 ... x1+1 ) {
            if( !rayCanPass(x,y) )
                return false;

            error -= deltay;
            if ( error < 0 ) {
                y = y + ystep;
                error = error + deltax;
            }
        }
    return true;
}*/

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
