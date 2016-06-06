#ifndef HOLDABLEOBJECT_H
#define HOLDABLEOBJECT_H

#include "Object.h"

class HoldableObject : public Object
{
public:
    HoldableObject(int weight, int objectType=OBJECT_HOLDABLE);

protected:
    int weight;
};

#endif // HOLDABLEOBJECT_H
