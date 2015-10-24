#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
	public:
		/* @pre:
		   @post: construct a cow -- name: cow, sound: Mow
		*/
		Cow();   
		/* @pre:
		   @post: get the value (double) of the cow produced
		*/
		double getMilkProduced() const;
		/* @pre:
		   @post: set the amount (double) of mill the cow produced
		*/
		void setMilkProduced(double gallons);
	
	protected:
		double m_milkProduced;
};

#endif
