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
<<<<<<< HEAD
    Coordinate(const int x,const int y);
=======
    Coordinate(int x, int y);
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade

    int getX() const;
    int getY() const;

<<<<<<< HEAD
    void setX(const int x);
    void setY(const int y);
=======
    void setX( int x);
    void setY( int y);
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade

private:
    int coordX;
    int coordY;
};

<<<<<<< HEAD
Coordinate operator+(const Coordinate &A,const Coordinate &B);
Coordinate operator-(const Coordinate &A,const Coordinate &B);
bool operator==(const Coordinate &A,const Coordinate &B);
unsigned int norm1(const Coordinate &A,const Coordinate &B);
=======
Coordinate operator+(Coordinate A,Coordinate B);
Coordinate operator-(Coordinate A,Coordinate B);
bool operator==(Coordinate A,Coordinate B);
int norm1(Coordinate A,Coordinate B);
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
std::ostream & operator<<(std::ostream&, const Coordinate&);

#endif //MOSP_COORDINATE_H
