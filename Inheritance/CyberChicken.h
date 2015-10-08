#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"

class CyberChicken : public Chicken
{
	public:
		/*@pre:
		  @post: set m_name to "CyberChicken" and m_sound to "Resistance is futile"
		*/
		CyberChicken();
		/* @pre:
		   @post: get the amount of eggs(int) produced
		*/
		int getCyberEggs() const;
		/* @pre:
		   @post: set the amount of eggs produced
		*/
		void setCyberEggs(int eggs);
};

#endif	
	
