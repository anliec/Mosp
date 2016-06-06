#include "wearable.h"

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
