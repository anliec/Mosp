//
// Created by nicolas on 03/08/15.
//

#include "Coordinate.h"

Coordinate::Coordinate(const int x,const int y)
{
    setX(x);
    setY(y);
}

int Coordinate::getX() const { return coordX; }

int Coordinate::getY() const { return coordY; }

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
    return std::abs(A.getX()-B.getX())+std::abs(A.getY()-B.getY());
}

std::ostream & operator<<(std::ostream& Str, Coordinate const& coordinate) {
    Str << "(" << coordinate.getX() << ";" << coordinate.getY() << ")";
    return Str;
}
