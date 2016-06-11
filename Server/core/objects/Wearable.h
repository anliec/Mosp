#ifndef WEARABLE_H
#define WEARABLE_H

#include "core/objects/HoldableObject.h"
#include "core/spec/Attributs.h"

class Wearable : public HoldableObject
{
public:

    Attributs getAttributs() const;
    int getClotheType() const;

    QJsonObject toJson() const;

    Wearable(int weight, int clotheType, Attributs attributs, int objectType =OBJECT_WEARABLE);

protected:
    int clotheType;
    Attributs attributs;
};

#endif // WEARABLE_H
