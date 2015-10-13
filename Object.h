//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_OBJECT_H
#define MOSP_OBJECT_H

#define OBJECT_UNKNOWN 0
#define OBJECT_HOLDABLE 1
#define OBJECT_INTERACTIVE 2

class Object {
public:
    Object(int objectType = OBJECT_UNKNOWN );

    int getType();

private:
    int type;
};


#endif //MOSP_OBJECT_H
