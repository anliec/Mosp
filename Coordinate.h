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
    Coordinate(int x, int y);

    int getX() const;
    int getY() const;

    void setX( int x);
    void setY( int y);

private:
    int coordX;
    int coordY;
};

Coordinate operator+(Coordinate A,Coordinate B);
Coordinate operator-(Coordinate A,Coordinate B);
bool operator==(Coordinate A,Coordinate B);
int norm1(Coordinate A,Coordinate B);
std::ostream & operator<<(std::ostream&, const Coordinate&);

#endif //MOSP_COORDINATE_H
