//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_LIVING_H
#define MOSP_LIVING_H

#include <string>

#include "Coordinate.h"

#define LIVING_UNUSABLE 0
#define LIVING_NONPLAYER 1
#define LIVING_FIGHTER 2
#define LIVING_PLAYER 21
#define LIVING_MONSTER 22

class Living {
public:
    Living(int className =LIVING_UNUSABLE,std::string livingName ="name unset", Coordinate livingCoordinate = Coordinate(-1,-1));

    void setCoordinate(const Coordinate livingCoordinate);
    Coordinate getCoordinate() const;

private:
    Coordinate coordinate;
    std::string name;
    int className;
};

#endif //MOSP_LIVING_H
