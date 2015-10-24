#ifndef ANIMAL_PEN
#define ANIMAL_PEN

#include <iostream>
#include "Stack.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"

class AnimalPen : public Stack<FarmAnimal*>
{
	public:
		/* @pre: --
		   @post: create an Animal Pen that has a stack structure
		*/
		AnimalPen();
		/* @pre: Animal Pen (stack) may be empty or loaded with animals
		   @post: remove everything contained in the stack
		*/
		~AnimalPen();
		/* @pre: --
		   @post: add animal pointers to the stack
		*/
		void add(FarmAnimal* animal);
		/* @pre: --
		   @post: look at the animal pointer at the top of the stack and return that pointer
		*/
		FarmAnimal* peekAtNextAnimal();
		/* @pre: --
		   @post: remove the animal pointer at the top and delete the object that animal pointer is pointing at
		*/
		void releaseAnimal();
		/* @pre: -- 
		   @post: check if the Pen(stack) is empty
		*/
		bool isPenEmpty();
	
};

#endif
