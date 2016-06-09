#include "Bag.h"

Bag::Bag()
{

}

std::vector<HoldableObject> & Bag::getItems()
{
    return items;
}

int Bag::getMoney() const
{
    return money;
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
