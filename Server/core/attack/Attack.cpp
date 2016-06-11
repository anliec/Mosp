#include "Attack.h"
#include "AttackRange.h"

#include <QJsonArray>

Attack::Attack(const std::string name, const std::vector<AttackRange> ranges, const std::vector<Effect> effects,\
               const int actionPointCost, const int minRange, const int maxRange):\
                    name(name),ranges(ranges),effects(effects),actionPointCost(actionPointCost),\
                    minRange(minRange),maxRange(maxRange), id(-1)
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

QJsonObject Attack::toJson() const
{
    QJsonObject json;
    json.insert("id",id);
    json.insert("name",name.c_str());
    json.insert("level",level);
    json.insert("actionPointCost",actionPointCost);
    json.insert("minRange",minRange);
    json.insert("maxRange",maxRange);
    QJsonArray effectsArray;
    for(Effect e:effects)
    {
        effectsArray.push_back(e.toJson());
    }
    json.insert("effects",effectsArray);
    QJsonArray rangeArray;
    for(AttackRange r:ranges)
    {
        rangeArray.push_back(r.toJson());
    }
    json.insert("ranges",rangeArray);
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
