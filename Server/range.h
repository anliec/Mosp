#ifndef RANGE_H
#define RANGE_H

#include "core/spec/value.h"

class Range
{
public:
    int getMaxRange() const;
    int getMinRange() const;
    int getType() const;

    Value randomRangeValue() const;

    Range(int type =0, int maxRange =0, int minRange =0);
protected:
    int maxRange;
    int minRange;
    int type;
};

#endif // RANGE_H
