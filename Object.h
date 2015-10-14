//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_OBJECT_H
#define MOSP_OBJECT_H

#define OBJECT_UNKNOWN 0
#define OBJECT_HOLDABLE 1
<<<<<<< HEAD
#define OBJECT_WEARABLE 11
#define OBJECT_WEAPON 111
=======
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
#define OBJECT_INTERACTIVE 2

class Object {
public:
    Object(int objectType = OBJECT_UNKNOWN );

<<<<<<< HEAD
    int getType() const;
=======
    int getType();
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade

private:
    int type;
};


#endif //MOSP_OBJECT_H
