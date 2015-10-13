//
// Created by nicolas on 03/08/15.
//

#include "Living.h"

Living::Living(Coordinate livingCoordinate): coordinate(livingCoordinate)
{

}

void Living::setCoordinate(Coordinate livingCoordinate)
{
    coordinate = livingCoordinate;
}

Coordinate Living::getCoordinate() { return coordinate; }