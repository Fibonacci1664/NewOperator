/*
 * Object.h
 *
 *  Created on: 10 Jul 2019
 *      Author: Dave
 */

#ifndef OBJECT_H_
#define OBJECT_H_
#include<iostream>

using namespace std;

class Object
{
private:
	string type;

public:
	Object();
	virtual ~Object();

	void setType(string type);
	void printDescription();
};

#endif /* OBJECT_H_ */
