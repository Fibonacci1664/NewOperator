/*
 * Animal.h
 *
 *  Created on: 9 Jul 2019
 *      Author: Dave
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include<iostream>

using namespace std;

class Animal
{
private:
	string name;

public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();

	void setName(string name);
	void speak() const;


};

#endif /* ANIMAL_H_ */
