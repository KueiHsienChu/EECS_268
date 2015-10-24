#include "AnimalPen.h"

AnimalPen::AnimalPen()
{
}

AnimalPen::~AnimalPen()
{
	while(!isPenEmpty())
		releaseAnimal();
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
	if(temp -> getName() == "CyberChicken")
	{
		std::cout << temp -> getName() << " destructor called.\n";
		std::cout << "Chicken destructor called.\n";
	}
	if(temp -> getName() == "Chicken")
		std::cout << temp -> getName() << " destructor called.\n";
	pop();
	delete temp;
	temp = nullptr;	
}

bool AnimalPen::isPenEmpty()
{
	
	return(isEmpty());

}
