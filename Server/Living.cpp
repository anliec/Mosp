//
// Created by nicolas on 03/08/15.
//

#include "Living.h"

Living::Living(int className, std::string livingName, Coordinate livingCoordinate):\
    coordinate(livingCoordinate), name(livingName),\
    className(className)
{

}

void Living::setCoordinate(const Coordinate livingCoordinate)
{
    coordinate = livingCoordinate;
}

Coordinate Living::getCoordinate() const { return coordinate; }

