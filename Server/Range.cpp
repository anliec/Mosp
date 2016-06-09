#include "Range.h"

#include <stdlib.h>
#include <time.h>

Range::Range(int type, int maxRange, int minRange):type(type),maxRange(maxRange),minRange(minRange)
{

}

int Range::getMaxRange() const
{
    return maxRange;
}

int Range::getMinRange() const
{
    return minRange;
}

int Range::getType() const
{
    return type;
}

Value Range::randomRangeValue() const
{
    Value ret(type);

    srand(time(NULL)); //intialise pseudo random genrator using currant time as seed
    ret.setValue( rand()%(maxRange-minRange+1)+minRange); //compute a random value between maxRange and minRange

    return ret;
}
