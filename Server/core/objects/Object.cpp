//
// Created by nicolas on 03/08/15.
//

#include "Object.h"

Object::Object(int objectType): type(objectType)
{
    id=-1;
}

int Object::getType() const { return type; }

QJsonObject Object::toJson() const
{
    QJsonObject json;
    json.insert("id",QJsonValue(id));
    json.insert("type",QJsonValue(type));
    return json;
}
