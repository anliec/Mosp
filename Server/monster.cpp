#include "monster.h"

Monster::Monster(int experienceFactor, std::vector<ObjectDrop> dropable, int level,\
                 Attributs attributs, std::vector<Attack> attacks,\
                 std::vector<Effect> effects, int className, std::string livingName,\
                 Coordinate livingCoordinate):\
    Fighter(level,attributs,attacks,effects,className,livingName,livingCoordinate),\
    experienceFactor(experienceFactor), dropable(dropable)
{

}

