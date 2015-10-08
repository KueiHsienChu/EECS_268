#include "FarmAnimal.h"
#include "AnimalPen.h"
#include <iostream>


void menu();

int main()
{
	int choice = 0;	
	double gallons_of_milk = 0.0;
	int num_of_eggs = 0;
	AnimalPen myPen;
	std::string yes_no = "";
	bool endloop = false;
	
	do
	{	
		menu();
				if(myPen.isPenEmpty())
					std::cout << "empty!";
		
		std::cout << "choice";
		std::cin >> choice;
		do//temporary menu design
		{
			if(choice == 1)
			{
				Cow* a1 = new Cow();
				
				std::cout << "How many gallons of milk did this cow peoduce?: ";
				std::cin >> gallons_of_milk;
				a1 -> setMilkProduced(gallons_of_milk);
				myPen.add(a1);
				a1 = nullptr;
				
				if(!myPen.isPenEmpty())
					std::cout << "Not empty!";
			}
			else if(choice == 2)
			{
				std::cout << "Add an eggless chicken to the pen? Ok. You're the boss.";
			}
			else if(choice == 3)
			{
				std::cout << "How many eggs does this cyber chicken produce?: ";
				std::cin >> num_of_eggs;
			}
			else
			{
				std::cout << "Please enter a valid choice.";
			}
		}while(choice > 3 || choice < 1);
		
		//ask the user if enough animal is added to the pen
		std::cout << "Done adding animals? (y/n)";
		std::cin >> yes_no;
		if(yes_no == "y" || yes_no == "yes" || yes_no == "Y")
			endloop = true; 								
		
	}while(endloop == false);





return 0;
}

void menu()
{
	std::cout << "Select an Animal to add to the Pen: \n";
	std::cout << "1)Cow (produces milk) \n";
	std::cout << "2)Chicken (cannot lay eggs) \n";
	std::cout << "3)Cyber Chicken (seems dangerous, but lay eggs) \n";
	std::cout << "-------------------------------------\n";
}
