#ifndef FIGHTER_H
#define FIGHTER_H

#include <vector>

#include "core/living/Living.h"
#include "core/spec/attributs.h"
#include "core/attack/attack.h"
#include "core/attack/damage.h"
#include "core/attack/effect.h"

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
