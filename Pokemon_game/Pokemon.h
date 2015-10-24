//Pokemon.h
#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
	public:
		Pokemon();//constructor
		void reduceHP(int amount); //reduce hp by the amount; does not prevent m_hp to be negative
		void setHP(int hp);
		void setAtk_lvl(int atk);
		void setDef_lvl(int def);
		void setName(std::string name);

		int getHP() const;
		int getAtk_lvl() const;
		int getDef_lvl() const;
		std::string getName() const;
	private:
		int m_hp; //hp of the pokemon
		int m_Atk_lvl; //attack level
		int m_Def_lvl; //denfense level
		std::string m_name; //name of the pokemon


};

#endif
