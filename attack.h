#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <vector>

#include "range.h"
#include "effect.h"
#include "damage.h"

class Attack
{
public:
    std::string getName() const;
    std::vector<Range> getRanges() const;
    std::vector<Effect> getEffects() const;
    int getActionPointCost() const;
    int getMinRange() const;
    int getMaxRange() const;

    Damage randomDamage() const;

    Attack( const std::string name, const std::vector<Range> ranges, const std::vector<Effect> effects,\
           const int actionPointCost, const int minRange =1, const int maxRange =1);

protected:
    const std::string name;
    int level;
    std::vector<Range> ranges;
    std::vector<Effect> effects;
    int actionPointCost;
    int minRange;
    int maxRange;
};

#endif // ATTACK_H
