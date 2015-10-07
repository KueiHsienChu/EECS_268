#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
	public:
		/* @pre:
		   @post:
		*/
		Cow();
		double getMilkProduced() const;
		void setMilkProduced(double gallons);
	
	protected:
		double m_milkProduced;
};

#endif
