#ifndef WEAPON_H
#define WEAPON_H

#include "core/objects/wearable.h"
#include "core/attack/attack.h"

class Weapon : public Wearable
{
public:
    Weapon(int weight, int clotheType, Attributs attributs,Attack attack, int objectType =OBJECT_WEAPON);

protected:
    Attack attack;
};

#endif // WEAPON_H
