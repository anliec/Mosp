#include "Attack.h"
#include "AttackRange.h"

Attack::Attack(const std::string name, const std::vector<AttackRange> ranges, const std::vector<Effect> effects,\
               const int actionPointCost, const int minRange, const int maxRange):\
                    name(name),ranges(ranges),effects(effects),actionPointCost(actionPointCost),\
                    minRange(minRange),maxRange(maxRange)
{

}

std::string Attack::getName() const
{
    return name;
}

std::vector<AttackRange> Attack::getRanges() const
{
    return ranges;
}

std::vector<Effect> Attack::getEffects() const
{
    return effects;
}

int Attack::getActionPointCost() const
{
    return actionPointCost;
}

int Attack::getMinRange() const
{
    return minRange;
}

int Attack::getMaxRange() const
{
    return maxRange;
}

Damage Attack::randomDamage() const
{
    std::vector<AttackValue> damageValues;
    for(unsigned int i=0 ; i<ranges.size() ; i++)
    { //get a random value for each range
        damageValues.push_back(ranges.at(i).randomRangeValue());
    }
    return Damage(damageValues,effects);
}
