#ifndef BAG_H
#define BAG_H

#include <vector>

#include "core/objects/HoldableObject.h"

class Bag
{
public:
    Bag();

    std::vector<HoldableObject> & getItems();
    int getMoney() const;
    int getId() const;

    bool addMoney(const int & moneyToAdd);

protected:
    int id;
    std::vector<HoldableObject> items;
    int money;
};

#endif // BAG_H
