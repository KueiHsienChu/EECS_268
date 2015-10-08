#ifndef ANIMAL_PEN
#define ANIMAL_PEN

#include "Stack.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"

class AnimalPen : public Stack<FarmAnimal*>
{
	public:
		AnimalPen();
		~AnimalPen();
		void add(FarmAnimal* animal);
		FarmAnimal* peekAtNextAnimal();
		void releaseAnimal();
		bool isPenEmpty();
	
};

#endif
