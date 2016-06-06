#ifndef BAG_H
#define BAG_H

#include <vector>

#include "core/objects/holdableobject.h"

class Bag
{
public:
    Bag();

    std::vector<HoldableObject> & getItems();
    int getMoney() const;

    bool addMoney(const int & moneyToAdd);

protected:
    std::vector<HoldableObject> items;
    int money;
};

#endif // BAG_H
