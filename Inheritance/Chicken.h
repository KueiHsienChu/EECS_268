#ifndef CHICKEN_H
#define CHICKEN_H

class Chicken : public FarmAnimal
{
	public:
		/*@pre:
		  @post: Set name to "Chicken" and sound to "Cluck";
		*/
		Chicken();

	protected:
		int getEggs() const;
		void setEggs(int Eggs);
		int m_eggs;
};

#endif		
