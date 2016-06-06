#include "fighter.h"

Fighter::Fighter(int level, Attributs attributs, std::vector<Attack> attacks, std::vector<Effect> effects,\
                 int className, std::string livingName, Coordinate livingCoordinate):\
    Living(className,livingName,livingCoordinate),\
    level(level), attributs(attributs), attacks(attacks), effects(effects)
{

}

void Fighter::receiveDamages(Damage &damage)
{
    attributs.applyDefenseFixResistances(damage);
    attributs.applyDefenseRelativeResistances(damage);
    attributs.looseLiveFromDamage(damage);
}

Damage Fighter::useAttack(unsigned int attackNumber) const
{
    Damage ret = attacks.at(attackNumber).randomDamage();
    attributs.applyAttackRelativeBonnus(ret);
    attributs.applyAttackFixBonnus(ret);
    return ret;
}
