/*
 * Main.cpp
 *
 *  Created on: 9 Jul 2019
 *      Author: Dave
 */

#include<iostream>
#include"Animal.h"
#include"Object.h"

using namespace std;

// PLEASE SEE LESSON 49 Udemy course C++

Animal *createAnimal()
{
	Animal *pAnimal = new Animal();				// Constructor called
	pAnimal->setName("Bertie");
	return pAnimal;				// Temp return obj is created as a copy of the original object
							// The copy constructor would be called.
}

Object *createObject()
{
	Object *pObj = new Object();
	return pObj;
}



int main()
{
	// Standard method of creating an object.
	Animal cat;
	cat.setName("Freddie");
	cat.speak();
	//delete cat;			// You cannot put a manual call in to deallocate memory if the memory
							// was allocated automatically.

	// Alternative, and a more manual way of creating objects

	Animal *pCat1 = new Animal();	// 'new' operator allocates memory explicitly, has to be managed manually
	pCat1->setName("Bob");			// normal dot syntax cannot be used on pointers, even using the star to
									// try and dereference will not work as the dot operator has higher
									// precedence that the star or dereference operator.

									// There is a work around but its not very nice to read syntactically
									// you can simply change the order of precedence by placing parenthesis
									// around the dereferenced variable, so it would look like this.

									// (*pCat1).setName("Bob);
									// This allow the use of the standard dot syntax. or you could just use
									// an arrow, which the ide will automatically place one for you if you
									// try to use dot syntax.
	pCat1->speak();
									/*
									 * If the code is run at this point it will not destroy the bob animal
									 * that was created as the 'new' operator was used when creating the
									 * object and so memory allocation and deallocation must be done
									 * manually. It is situations like this that cause things like
									 * memory leaks, where an object is no longer in use or even in scope
									 * and should have been destroyed but has not been.
									 */

	delete pCat1;					/*
									 * This is how we manually deallocate memory (call the deconstructor)
									 * This should always be done when the new operator keyword has been
									 * invoked to create a new object.
									 */

	/*
	 * What we are trying to achieve here is a way of being able to return an object by way
	 * of using a method call, but without first having to create the object itself in order to
	 * be able to use that method. (BONKERS).
	 *
	 * If we however make the method at the top a reference and also the frog variable then we
	 * end up with the problem of trying to access a reference to the Animal obj 'a' back in the
	 * method via the referenced frog variable, this is a problem because the Animal obj 'a' will
	 * have gone out of scope and so we end up with a reference to nothing.
	 *
	 * Long story short, NEVER RETURN A REFERENCE BACK TO A LOCAL VARIBLE!
	 *
	 * A common way around this problem is to use pointers.
	 *
	 * By using pointer NO copies are made and so this is much more effiecient.
	 */
	Animal *pFrog = createAnimal();	// 'frog' is actually a copy of the returned obj from the
									// createAnimal function, which is in itself a copy of the
									// original Animal obj

									/*
									 * Due to the optimisation of the compiler though these
									 * optimisations are hidden from us and so we dont see the
									 * message displayed informing us that the copy constructor
									 * was called.
									 *
									 * This may not always be the case though and so the above
									 * method of creating an object could very well be inefficient
									 * due to the amount of copies that had to be made.
									 */

	pFrog->speak();
	delete pFrog;					// Remember to deallocate the memory when the 'new' operator
									// has been invoked.



	// What follows is some practice objects.



	cout << endl;
	cout << "############################################" << endl;
	cout << endl;

	// Standard object creation, memory is managed by the system.
	Object obj_1;
	obj_1.setType("Sword");
	obj_1.printDescription();

	cout << endl;
	cout << "############################################" << endl;
	cout << endl;

	/*
	 * Using a pointer to manually allocate memory to a 'new' object.
	 * Remember dot syntax cannot be used on pointers, you must use the arrow symbol ->.
	 */
	Object *pObj_2 = new Object();
	pObj_2->setType("Mace");
	pObj_2->printDescription();
	delete pObj_2;

	cout << endl;
	cout << "############################################" << endl;
	cout << endl;


	Object *pRandObj = createObject();
	pRandObj->setType("Random Object");
	pRandObj->printDescription();
	delete pRandObj;

	cout << endl;
	cout << "############################################" << endl;
	cout << endl;




	return 0;
}


