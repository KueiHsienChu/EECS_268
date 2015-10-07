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
		int getCyberEggs() const;
		void setCyberEggs(int eggs);
};

#endif	
	
