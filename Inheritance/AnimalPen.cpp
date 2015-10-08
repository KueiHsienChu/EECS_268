#include "AnimalPen.h"

AnimalPen::AnimalPen()
{
}

AnimalPen::~AnimalPen()
{
}

void AnimalPen::add(FarmAnimal* animal)
{
	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal()
{//not working
	return(peek());
}

void AnimalPen::releaseAnimal()
{
	//remember the stack is full of pointers
	pop();
}

bool AnimalPen::isPenEmpty()
{
	
	return(isEmpty());

}
