#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include<iostream>


class FarmAnimal
{
	public:
		/* @pre:
		   @post: Sets name and sound to the string "unset" by default
		*/
		FarmAnimal();
		/* @pre:
		   @post:
		*/
		std::string getName() const;
		void setName(std::string name);
		std::string getSound() const;
		void setSound(std::string sound);
	
	protected:
		std::string m_name;
		std::string m_sound;
};

#endif
