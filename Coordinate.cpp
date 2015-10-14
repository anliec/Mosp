//
// Created by nicolas on 03/08/15.
//

#include "Coordinate.h"

<<<<<<< HEAD
Coordinate::Coordinate(const int x,const int y)
=======
Coordinate::Coordinate(int x, int y)
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
{
    setX(x);
    setY(y);
}

int Coordinate::getX() const { return coordX; }

int Coordinate::getY() const { return coordY; }

<<<<<<< HEAD
void Coordinate::setX(const int x) { coordX = x; }

void Coordinate::setY(const int y) { coordY = y; }

Coordinate operator+(const Coordinate &A,const Coordinate &B) {
    return Coordinate(A.getX()+B.getX(),A.getY()+B.getY());
}

Coordinate operator-(const Coordinate &A,const Coordinate &B) {
    return Coordinate(A.getX()-B.getX(),A.getY()-B.getY());
}

bool operator==(const Coordinate &A,const Coordinate &B){
    return A.getY() == B.getY() && A.getX() == B.getX();
}

unsigned int norm1(const Coordinate &A, const Coordinate &B){
=======
void Coordinate::setX( int x) { coordX = x; }

void Coordinate::setY(int y) { coordY = y; }

Coordinate operator+(Coordinate A, Coordinate B) {
    return Coordinate(A.getX()+B.getX(),A.getY()+B.getY());
}

Coordinate operator-(Coordinate A, Coordinate B) {
    return Coordinate(A.getX()-B.getX(),A.getY()-B.getY());
}

bool operator==(Coordinate A,Coordinate B){
    return A.getY() == B.getY() && A.getX() == B.getX();
}

int norm1(Coordinate A,Coordinate B){
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
    return std::abs(A.getX()-B.getX())+std::abs(A.getY()-B.getY());
}

std::ostream & operator<<(std::ostream& Str, Coordinate const& coordinate) {
    Str << "(" << coordinate.getX() << ";" << coordinate.getY() << ")";
    return Str;
<<<<<<< HEAD
}
=======
}
>>>>>>> 54b6715a672a94850a3118be7ae35cd548373ade
