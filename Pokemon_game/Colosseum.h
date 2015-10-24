//Colosseum.h
#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include "Pokemon.h"
#include "Dice.h"
#include <iostream>
#include <string>


class Colosseum
{
	public:
		Colosseum();//insializes Dice to appropriate sizes
		void userBuild(Pokemon& p);
		//Sets all the value for name, hp, attack level and
		//defense level of the Pokemon passed in
		bool attack(const Pokemon& attacker, Pokemon& defender);
		/*The attacker is trying to hit the defender
		Calculate attack and defense bonuses:
		use d20 to roll random values for and attackBonus and a defenseBonus
		Determine if the attack hits
		if the attacker's attackLevel + attackBonus is greater than the defender's defenseLevel + defenseBonus the attack hits
		Determine how much damage the attack does (if it hit)
		roll three d6's, add them up, and that is the damage
		Displays information about the attack
		display all attack information as reflected in the sample runs
		Determine if the player died from the attack
		return true only if the opponent died because of the attack, otherwise returns false*/
		void play(Pokemon& p1, Pokemon& p2);
		/*Handles the 10 round fight between p1 and p2
		Uses a 2-sided die to decide who goes first
		Display round information and calls attack() to display attack information
		Determines when the game is over*/
	private:
		Dice d20;
		Dice d6;

};

#endif
