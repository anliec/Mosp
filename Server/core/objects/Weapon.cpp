#include "Weapon.h"

Weapon::Weapon(int weight, int clotheType, Attributs attributs, Attack attack, int objectType):\
    Wearable(weight,clotheType,attributs,objectType),\
    attack(attack)
{

}

