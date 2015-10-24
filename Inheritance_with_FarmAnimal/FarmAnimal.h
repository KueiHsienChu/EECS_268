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
		   @post: get the animal's name
		*/
		std::string getName() const;
		/* @pre:
		   @post: set the animal's name
		*/
		void setName(std::string name);
		/* @pre:
		   @post: get the animal's sound
		*/
		std::string getSound() const;
		/* @pre:
		   @post: set the animal's sound
		*/
		void setSound(std::string sound);
	
	protected:
		std::string m_name;
		std::string m_sound;
};

#endif
