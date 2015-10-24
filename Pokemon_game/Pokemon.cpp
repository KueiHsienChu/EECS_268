//Pokemon.cpp
#include "Pokemon.h"

Pokemon::Pokemon()
{
	m_hp = 0;
	m_Atk_lvl = 0;
	m_Def_lvl = 0;
	m_name = "";
}


void Pokemon::reduceHP(int amount)
{
	m_hp -= amount;
}


void Pokemon::setHP(int hp)
{
	m_hp = hp;
}

void Pokemon::setAtk_lvl(int atk)
{
	m_Atk_lvl = atk;
}

void Pokemon::setDef_lvl(int def)
{
	m_Def_lvl = def;
}

void Pokemon::setName(std::string name)
{
	m_name = name;
}

int Pokemon::getHP() const
{
	return(m_hp);
}

int Pokemon::getAtk_lvl() const
{
	return(m_Atk_lvl);
}

int Pokemon::getDef_lvl() const
{
	return(m_Def_lvl);
}

std::string Pokemon::getName() const
{
	return(m_name);
}




