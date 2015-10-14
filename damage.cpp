#include "damage.h"

Damage::Damage(const std::vector<Value> values,const std::vector<Effect> effects)
    : values(values),effects(effects)
{

}

Damage Damage::operator *(double factor) const
{
    std::vector<Value> retValues;
    for(int i=0 ; i<values.size() ; i++)
    {
        retValues.push_back(values.at(i)*factor);
    }
    return Damage(retValues,effects);
}

Damage & Damage::operator *=(double factor)
{
    for(int i=0 ; i<values.size() ; i++)
    {
        values[i] *= factor;
    }
    return *this;
}

std::vector<Effect> Damage::getEffects() const
{
    return effects;
}

std::vector<Value> Damage::getValues() const
{
    return values;
}
