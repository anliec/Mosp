#include "Bag.h"

Bag::Bag()
{
    id=-1;
}

std::vector<HoldableObject> & Bag::getItems()
{
    return items;
}

int Bag::getMoney() const
{
    return money;
}

int Bag::getId() const
{
    return id;
}

bool Bag::addMoney(const int &moneyToAdd)
{
    if(moneyToAdd + money < 0)
    {
        return false;
    }
    else
    {
        money += moneyToAdd;
        return true;
    }
}
