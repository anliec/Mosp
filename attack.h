#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <vector>

#include "attackrange.h"
#include "effect.h"
#include "damage.h"

class Attack
{
public:
    std::string getName() const;
    std::vector<AttackRange> getRanges() const;
    std::vector<Effect> getEffects() const;
    int getActionPointCost() const;
    int getMinRange() const;
    int getMaxRange() const;

    Damage randomDamage() const;

    Attack( const std::string name, const std::vector<AttackRange> ranges, const std::vector<Effect> effects,\
           const int actionPointCost, const int minRange =1, const int maxRange =1);

protected:
    const std::string name;
    int level;
    std::vector<AttackRange> ranges;
    std::vector<Effect> effects;
    int actionPointCost;
    int minRange;
    int maxRange;
};

#endif // ATTACK_H
