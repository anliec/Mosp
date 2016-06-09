#include "Wearable.h"

Wearable::Wearable(int weight, int clotheType, Attributs attributs, int objectType):\
    HoldableObject(weight, objectType),\
    clotheType(clotheType),\
    attributs(attributs)
{

}

int Wearable::getClotheType() const
{
    return clotheType;
}

Attributs Wearable::getAttributs() const
{
    return attributs;
}

QJsonObject Wearable::toJson() const
{
    QJsonObject json;
    json = Object::toJson();
    json.insert("attributs",QJsonValue(attributs.toJson()));
}
