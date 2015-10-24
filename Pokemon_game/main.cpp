#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"

int main()
{
	//start declaring
 	Pokemon play1;
 	Pokemon play2;
	Colosseum c1; 
	std::string answer;
	bool repeat = false;

	do
	{
	//announcement
	std::cout<< "Player 1, build your Pokemon!\n=====================\n";
	c1.userBuild(play1);
	std::cout<< "Player 2, build your Pokemon!\n=====================\n";
	c1.userBuild(play2);
	std::cout<< "Choosing which player will go first by throwing the two-sided dice:";

	//play
	c1.play(play1, play2);
	
	std::cout<< "Do you want to play again? (y/n)";
	std::cin>> answer;
	std::cout<< "\n";
	//condition for repeating the gmae
	if(answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "Yes")
		repeat = true;
	else
		repeat = false;		
	}while(repeat == true);
	
	std::cout<< "Thanks for playing!\n";
	return 0;
}
