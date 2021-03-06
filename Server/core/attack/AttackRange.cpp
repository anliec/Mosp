#include "AttackRange.h"

AttackRange::AttackRange(int type, int maxRange, int minRange, int attackType):\
    Range(type,maxRange,minRange), attackType(attackType)
{

}

AttackRange::AttackRange(Range range, int attackType):\
    Range(range), attackType(attackType)
{

}

AttackValue AttackRange::randomRangeValue() const
{
    return AttackValue(Range::randomRangeValue(),attackType);
}

QJsonObject AttackRange::toJson() const
{
    QJsonObject json;
    json = Range::toJson();
    json.insert("attackType",attackType);
    return json;
}
