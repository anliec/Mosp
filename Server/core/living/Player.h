#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "core/living/Fighter.h"
#include "core/objects/HoldableObject.h"
#include "core/objects/Wearable.h"
#include "core/objects/Weapon.h"
#include "core/objectManagement/Bag.h"

class Player : public Fighter
{
public:
    void updateAttributs();
    //algo: put in atributs the sum of the baseAttributs
    //      and from attribut of the clothes

    Player(Bag bag, std::vector<Wearable> clothes, Weapon activeWeapon,\
           int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
           int className =LIVING_PLAYER,std::string livingName ="name unset", Coordinate livingCoordinate = Coordinate(-1,-1));

protected:
    Attributs baseAttributs;
    Bag bag;
    std::vector<Wearable> clothes;
    Weapon activeWeapon;
};

#endif // PLAYER_H
