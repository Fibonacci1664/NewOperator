/*
 * Animal.cpp
 *
 *  Created on: 9 Jul 2019
 *      Author: Dave
 */

#include "Animal.h"

Animal::Animal()
{
	cout << "Animal created." << endl;
}

Animal::Animal(const Animal &other)
{
	name = other.name;
	cout << name << "Animal created by copying." << endl;
}

Animal::~Animal()
{
	cout << name << " Animal destroyed." << endl;
}

void Animal::setName(string name)
{
	this->name = name;
}

void Animal::speak() const
{
	cout << "My name is " << name << endl;
}

