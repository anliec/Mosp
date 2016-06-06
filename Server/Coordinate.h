//
// Created by nicolas on 03/08/15.
//

#ifndef MOSP_COORDINATE_H
#define MOSP_COORDINATE_H

#include <cmath>
#include <iosfwd>
#include <iostream>

class Coordinate {

public:
    Coordinate(const int x,const int y);

    int getX() const;
    int getY() const;

    void setX(const int x);
    void setY(const int y);

private:
    int coordX;
    int coordY;
};

Coordinate operator+(const Coordinate &A,const Coordinate &B);
Coordinate operator-(const Coordinate &A,const Coordinate &B);
bool operator==(const Coordinate &A,const Coordinate &B);
unsigned int norm1(const Coordinate &A,const Coordinate &B);

std::ostream & operator<<(std::ostream&, const Coordinate&);

#endif //MOSP_COORDINATE_H
