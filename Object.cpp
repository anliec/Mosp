//
// Created by nicolas on 03/08/15.
//

#include "Object.h"

Object::Object(int objectType): type(objectType)
{

}

int Object::getType() { return type; }