#ifndef COW_H
#define COW_H

class Cow : public FarmAnimal
{
	public:
		/* @pre:
		   @post:
		*/
		Cow();
		double getMilkproduced() const;
		void setMilkProduced(double gallons);
	
	protected:
		double m_milkProduced;
};

#endif
