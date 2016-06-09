#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H

#include "Living.h"

class NonPlayerCharacter : public Living
{
public:
    NonPlayerCharacter(int className =LIVING_NONPLAYER,std::string livingName ="name unset",\
                       Coordinate livingCoordinate = Coordinate(-1,-1));
};

#endif // NONPLAYERCHARACTER_H
