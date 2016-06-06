#include "damage.h"

Damage::Damage(const std::vector<AttackValue> values,const std::vector<Effect> effects)
    : values(values),effects(effects)
{

}

Damage Damage::operator *(double factor) const
{
    std::vector<AttackValue> retValues;
    for(unsigned i=0 ; i<values.size() ; i++)
    {
        retValues.push_back(values.at(i)*factor);
    }
    return Damage(retValues,effects);
}

Damage & Damage::operator *=(double factor)
{
    for(unsigned i=0 ; i<values.size() ; i++)
    {
        values[i] *= factor;
    }
    return *this;
}

std::vector<Effect> &Damage::getEffects()
{
    return effects;
}

std::vector<AttackValue> &Damage::getValues()
{
    return values;
}

AttackValue Damage::getValue(int index) const
{
    return values.at(index);
}

void Damage::setValue(const AttackValue &value, int index)
{
    values.at(index) = value;
}

int Damage::getMaxIndex() const
{
    return values.size();
}

