#ifndef DAMAGE_H
#define DAMAGE_H

#include <vector>
#include "attackvalue.h"
#include "effect.h"

class Damage
{
public:
    std::vector<AttackValue> & getValues();
    std::vector<Effect> & getEffects();

    Damage(const std::vector<AttackValue> values,const std::vector<Effect> effects);

    Damage operator *(double factor) const;
    Damage & operator *=(double factor);

protected:
    std::vector<AttackValue> values;
    std::vector<Effect> effects;
};

#endif // DAMAGE_H
