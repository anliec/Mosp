#ifndef OBJECTDROP_H
#define OBJECTDROP_H

#include "core/objects/HoldableObject.h"

class ObjectDrop
{
public:
    ObjectDrop(const HoldableObject object, const int dropFactor);

protected:
    HoldableObject object;
    int dropFactor;
};

#endif // OBJECTDROP_H
