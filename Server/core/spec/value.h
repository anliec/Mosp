#ifndef VALUE_H
#define VALUE_H

#include <vector>
#include <QJsonObject>

class Value
{
public:
    int getValue() const;
    int getType() const;
    void setValue(int newValue);

    Value(int type=0,int value=0);

    virtual QJsonObject toJson() const;

    Value operator *(double factor) const;
    Value & operator *=(double factor);
protected:
    int value;
    int type;
};

std::vector<Value> operator+(const std::vector<Value> v1,const std::vector<Value> v2);

#endif // VALUE_H
