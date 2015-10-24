//Colosseum.cpp
#include "Colosseum.h"
#include <string>
#include <iostream>

Colosseum::Colosseum()
{
	d20 = Dice(20);
	d6 = Dice(6);
}

void Colosseum::userBuild(Pokemon& p)
{	
	int hp = 0;//HP
	int atk = 0;//atk_lvl
	int def = 0;//def_lvl
	int ad_pts = 50;//total amount of atk and def

	std::string name;
	std::cout<< "Please name your Pokemon: "; 
	std::cin>> name;
	p.setName(name); //set name 
	
	std::cout<< "\nHow many hit points will it have? (1-50):";
	std::cin>> hp;
	while(hp > 50 || hp <= 0)
	{
		std::cout<< "\nThe hit point must be between 1 to 50:"; 
		std::cin>> hp;
	}
	p.setHP(hp); //set HP

	std::cout<< "\nSplit fifty points between attack level and defense level" << std::endl;
	//display message about atk level and def level
	
	std::cout<< "Enter your attack level (1-49):";
	std::cin>> atk; 
	while(atk >= 50 || atk <= 0)
	{
		std::cout<< "\nSorry. The attack level must be between 1 and 49:";
		std::cin>> atk;
	}
	p.setAtk_lvl(atk); // set atk pts
	ad_pts = 50 - atk; // set the rest atk and def points
	
	std::cout<< "\nEnter your defense level (1-" << ad_pts << "):";
	std::cin>> def;
	while(def > ad_pts || def <= 0)
	{
		std::cout<< "\nSorry. The defense level must be between 1 and " << ad_pts << ":";
		std::cin>> def;
	}
	p.setDef_lvl(def);//set def pts 
	std::cout<< "\n";

}


bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{

 
	int value_a = attacker.getAtk_lvl() + d20.roll(); // set up attacker points
	int value_d = defender.getDef_lvl() + d20.roll(); // set up defender points

	//info display
	std::cout<< attacker.getName() << " rolls an attack bonus of " << value_a << std::endl;
	std::cout<< defender.getName() << " rolls a defense bonus of " << value_d << std::endl;

	int h_reduce; // set up hp reduce amount
	bool hit = false; // set up hit or not -- default:false
	if(value_a > value_d)
	{
		hit = true;
		std::cout<< "The attack hits dealing 3-D6 damage!";
	}
	else
	{
		std::cout<< "The attack missed!" << std::endl;
	}
	
	if(hit == true)
	{
		int a1, a2, a3;
		a1 = d6.roll();
		a2 = d6.roll();
		a3 = d6.roll();
		h_reduce = a1 + a2 + a3;

		std::cout<< "\nThe rolls are " << a1 << ", " << a2 << ", and " << a3 << " totalling: " << h_reduce << " damages!"; 
		defender.reduceHP(h_reduce);
		
		//if the defender still have HP left, then display message	
		if(defender.getHP() >0)
			std::cout<< "\n" << defender.getName() << " has " << defender.getHP() << " hit points left\n";
		//else, display nothing
		else
		{
			std::cout<< "\n" << defender.getName() << " has been defeated!\n";	
		}
	}		
			
	if(defender.getHP() <= 0)
		return true;
	else
		return false; 
}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	int rounds = 10; // a total of ten rounds
	Dice d2(2); // 2 sided dice
	Colosseum C1;
	bool battle = false; //boolean -- default:false	
	int dice_r = 0; //dice result
	int round_number = 1; //round number
	while(rounds > 0)
	{
		//randomly select who goes first		
		dice_r = d2.roll();

		//condition for round 1
		if(dice_r == 1 && rounds == 10)
			std::cout<< "\nThe dice rolled a 1. Player 1 will go first!\n";
		else if(dice_r == 2 && rounds == 10)
			std::cout<< "\nThe dice rolled a 2. Player 2 will go first!\n";
		else
		{
		}
		//display round #
		std::cout<< "\nRound " << round_number << "!" << std::endl;

		//conditions for every round
		if(dice_r == 1)
		{
			battle = C1.attack(p1, p2);
			if(battle == true)
				rounds = 0;
			else
				battle = C1.attack(p2, p1);
			if(battle == true)
				rounds = 0;	
		}
		else
		{
			battle = C1.attack(p2, p1);
			if(battle == true)
				rounds = 0;	
			else
				battle = C1.attack(p1, p2);
			if(battle == true)
				rounds = 0;	
		}
	round_number++;
	rounds--;	
	}
}

