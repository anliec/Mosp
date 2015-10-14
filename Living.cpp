//
// Created by nicolas on 03/08/15.
//

#include "Living.h"

<<<<<<< HEAD
Living::Living(int className, std::string livingName, Coordinate livingCoordinate):\
    coordinate(livingCoordinate), name(livingName),\
    className(className)
=======
Living::Living(Coordinate livingCoordinate): coordinate(livingCoordinate)
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
{

}

<<<<<<< HEAD
void Living::setCoordinate(const Coordinate livingCoordinate)
=======
void Living::setCoordinate(Coordinate livingCoordinate)
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
{
    coordinate = livingCoordinate;
}

<<<<<<< HEAD
Coordinate Living::getCoordinate() const { return coordinate; }
=======
Coordinate Living::getCoordinate() { return coordinate; }
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
