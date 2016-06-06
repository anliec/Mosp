#include "attackvalue.h"

AttackValue::AttackValue(int value, int valueType, int attackType):\
    Value(value,valueType), attackType(attackType)
{

}

AttackValue::AttackValue(Value value, int attackType):\
    Value(value), attackType(attackType)
{

}

AttackValue AttackValue::operator *(double factor) const
{
    return AttackValue(type,value*factor,attackType);
}

AttackValue & AttackValue::operator *=(double factor)
{
    value *= factor;
    return *this;
}

int AttackValue::getAttackType() const
{
    return attackType;
}

std::vector<AttackValue> operator+(const std::vector<AttackValue> vA,const std::vector<AttackValue> vB)
{
    std::vector<AttackValue> ret;

    for(int i=0 ; i<vA.size() ; i++)
    {
        ret.push_back(vA.at(i));
    }
    for(int i=0 ; i<vB.size() ; i++)
    {
        ret.push_back(vB.at(i));
    }

    for(int i=0 ; i<ret.size() ; i++)
    {
        for(int n=i+1 ; n<ret.size() ; n++)
        {
            if(ret.at(i).getType() == ret.at(n).getType() && ret.at(i).getAttackType() == ret.at(n).getAttackType())
            {
                //if the two elements have the same type and attackType,
                //we put the sum in the first one
                ret.at(i).setValue(ret.at(i).getValue() + ret.at(n).getValue());
                //and we delete the segond one
                ret.erase(ret.begin() + n);
                n--;
            }
        }
    }
    return ret;
}
