#ifndef ATTACKVALUE_H
#define ATTACKVALUE_H

#include "value.h"

class AttackValue : public Value
{
public:
    AttackValue(int value =0,int valueType =0,int attackType =0);

private:
    int attackType;
};

#endif // ATTACKVALUE_H
