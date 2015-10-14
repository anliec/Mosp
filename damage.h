#ifndef DAMAGE_H
#define DAMAGE_H

#include <vector>
#include "value.h"
#include "effect.h"

class Damage
{
public:
    std::vector<Value> getValues() const;
    std::vector<Effect> getEffects() const;

    Damage(const std::vector<Value> values,const std::vector<Effect> effects);

    Damage operator *(double factor) const;
    Damage & operator *=(double factor);

protected:
    std::vector<Value> values;
    std::vector<Effect> effects;
};

#endif // DAMAGE_H
