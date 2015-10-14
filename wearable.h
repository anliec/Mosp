#ifndef WEARABLE_H
#define WEARABLE_H

#include "holdableobject.h"
#include "attributs.h"

class Wearable : public HoldableObject
{
public:

    Attributs getAttributs() const;
    int getClotheType() const;

    Wearable(int weight, int clotheType, Attributs attributs, int objectType =OBJECT_WEARABLE);

protected:
    int clotheType;
    Attributs attributs;
};

#endif // WEARABLE_H
