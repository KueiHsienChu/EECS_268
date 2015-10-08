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
	FarmAnimal* temp;
	temp = peek();
	return(temp);
}

void AnimalPen::releaseAnimal()
{
	//remember the stack is full of pointers
	FarmAnimal* temp;
	temp = peek();
	pop();
	delete temp;
	temp = nullptr;	
}

bool AnimalPen::isPenEmpty()
{
	
	return(isEmpty());

}
