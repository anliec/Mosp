#ifndef ATTACKRANGE_H
#define ATTACKRANGE_H

#include "Range.h"
#include "AttackValue.h"

class AttackRange : public Range
{
public:

    AttackValue randomRangeValue() const;

    AttackRange(int type =0, int maxRange =0, int minRange =0, int attackType=0);
    AttackRange(Range range, int attackType=0);

protected:
    int attackType;
};

#endif // ATTACKRANGE_H
