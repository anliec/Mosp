#ifndef DAMAGE_H
#define DAMAGE_H

#include <vector>
#include <QJsonObject>

#include "AttackValue.h"
#include "Effect.h"

class Damage
{
public:
    std::vector<AttackValue> & getValues();
    AttackValue getValue(int index) const;
    /* return the AttackVallue at index on values
     * don't do any check on values size.
     */
    void setValue(const AttackValue &value, int index);
    /* set the AttackVallue at index on values
     * don't do any check on values size.
     */
    int getMaxIndex() const;
    /* return the size of the values array.
     */
    std::vector<Effect> & getEffects();

    Damage(const std::vector<AttackValue> values,const std::vector<Effect> effects);

    Damage operator *(double factor) const;
    Damage & operator *=(double factor);

    QJsonObject toJson() const;

protected:
    std::vector<AttackValue> values;
    std::vector<Effect> effects;
};

#endif // DAMAGE_H
