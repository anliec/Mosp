#ifndef ATTACKVALUE_H
#define ATTACKVALUE_H

#include <vector>
#include "core/spec/value.h"

class AttackValue : public Value
{
public:

    int getAttackType() const;

    AttackValue operator *(double factor) const;
    AttackValue & operator *=(double factor);

    AttackValue(int value =0,int valueType =0,int attackType =0);
    AttackValue(Value value, int attackType=0);

    QJsonObject toJson() const;

protected:
    int attackType;
};

std::vector<AttackValue> operator+(const std::vector<AttackValue> v1,const std::vector<AttackValue> v2);

#endif // ATTACKVALUE_H
