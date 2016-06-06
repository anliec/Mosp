#ifndef MONSTER_H
#define MONSTER_H

#include <vector>

#include "fighter.h"
#include "objectdrop.h"

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
