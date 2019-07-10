/*
 * Object.cpp
 *
 *  Created on: 10 Jul 2019
 *      Author: Dave
 */

#include "Object.h"

Object::Object()
{
	cout << "An object was created" << endl;

}

Object::~Object()
{
	cout << "A " << type << " object was destroyed" << endl;
}

void Object::setType(string type)
{
	this->type = type;
}
void Object::printDescription()
{
	cout << "The type of object is a " << type << endl;
}

