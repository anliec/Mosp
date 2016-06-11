//
// Created by nicolas on 03/08/15.
//

#include "Living.h"

Living::Living(int className, std::string livingName, Coordinate livingCoordinate):\
    coordinate(livingCoordinate), name(livingName),\
    className(className)
{
    id=-1;
}

void Living::setCoordinate(const Coordinate livingCoordinate)
{
    coordinate = livingCoordinate;
}

Coordinate Living::getCoordinate() const { return coordinate; }

QJsonObject Living::toJson() const
{
    QJsonObject json;
    json.insert("id",id);
    json.insert("name",name.c_str());
    json.insert("className",className);
    json.insert("coordinate",coordinate.toJson());
    return json;
}
