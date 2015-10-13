//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_LIVING_H
#define MOSP_LIVING_H

#include "Coordinate.h"

class Living {
public:
    Living(Coordinate livingCoordinate = Coordinate(-1,-1));

    void setCoordinate(Coordinate livingCoordinate);
    Coordinate getCoordinate();

private:
    Coordinate coordinate;
};

#endif //MOSP_LIVING_H
