//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_OBJECT_H
#define MOSP_OBJECT_H

#define OBJECT_UNKNOWN 0
#define OBJECT_HOLDABLE 1
#define OBJECT_WEARABLE 11
#define OBJECT_WEAPON 111
#define OBJECT_INTERACTIVE 2

#include <QJsonObject>

class Object {
public:
    Object(int objectType = OBJECT_UNKNOWN);

    int getType() const;

    virtual QJsonObject toJson() const;

private:
    int id; //if id=-1 object is not in database
    int type;
};


#endif //MOSP_OBJECT_H
