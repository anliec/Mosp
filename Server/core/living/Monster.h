#ifndef MONSTER_H
#define MONSTER_H

#include <vector>

#include "core/living/Fighter.h"
#include "core/objectManagement/ObjectDrop.h"

class Monster : public Fighter
{
public:
    Monster(int experienceFactor, std::vector<ObjectDrop> dropable,\
            int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
            int className =LIVING_MONSTER,std::string livingName ="name unset", Coordinate livingCoordinate = Coordinate(-1,-1));

protected:
    int experienceFactor;
    std::vector<ObjectDrop> dropable;
};

#endif // MONSTER_H
