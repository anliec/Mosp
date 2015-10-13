//
// Created by nicolas on 03/08/15.
//

#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
    setX(x);
    setY(y);
}

int Coordinate::getX() const { return coordX; }

int Coordinate::getY() const { return coordY; }

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
    return std::abs(A.getX()-B.getX())+std::abs(A.getY()-B.getY());
}

std::ostream & operator<<(std::ostream& Str, Coordinate const& coordinate) {
    Str << "(" << coordinate.getX() << ";" << coordinate.getY() << ")";
    return Str;
}