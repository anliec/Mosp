#include "value.h"

Value::Value(int type, int value):type(type),value(value)
{

}

Value Value::operator *(double factor) const
{
    return Value(type, value*factor);
}
Value & Value::operator *=(double factor)
{
    value *= factor;
}

int Value::getType() const
{
    return type;
}

int Value::getValue() const
{
    return value;
}

void Value::setValue(int newValue)
{
    value = newValue;
}

std::vector<Value> operator+(const std::vector<Value> vA,const std::vector<Value> vB)
{
    std::vector<Value> ret;

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
            if(ret.at(i).getType() == ret.at(n).getType())
            {
                //if the two elements have the same type, we but the sum in the first one
                ret.at(i).setValue(ret.at(i).getValue() + ret.at(n).getValue());
                //and we delete the segond one
                ret.erase(ret.begin() + n);
                n--;
            }
        }
    }
    return ret;
}








