#ifndef FIGHTER_H
#define FIGHTER_H

#include <vector>

#include "Living.h"
#include "attributs.h"
#include "attack.h"
#include "damage.h"
#include "effect.h"

class Fighter : public Living
{
public:
    void receiveDamages(Damage & damage);
    Damage useAttack(unsigned int attackNumber) const;
    /*algo: get random damage from attack and then apply the
     *      modificator from attributs (first relative then fixe)
     */
    Fighter(int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
            int className =LIVING_FIGHTER,std::string livingName ="name unset", Coordinate livingCoordinate = Coordinate(-1,-1));

protected:
    int level;
    Attributs attributs;
    std::vector<Attack> attacks;
    std::vector<Effect> effects;
};

#endif // FIGHTER_H
