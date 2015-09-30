#include "Stack.h"
#include <iostream>

void printMenu(); //Menu


int main()
{
	int input = 0; //User input
	int value = 0; //User value input
	StackInterface<int>* pile1 = new Stack<int>();
	
	do{
		printMenu();
		std::cin >> input;
		switch(input)
		{
			case 1:
				{
					std::cout << "What is going in Stack 1?";	
					std::cin >> value;
					pile1 -> push(value);
					std::cout << value << " successfully added to stack 1";
					break;
				}
			case 2:
				{
					std::cout << pile1 -> peek() << " is at the top of stack 1";
					break;
				}
			case 3:
				{	
					pile1 -> print();
					break;
				}
			case 4:
				{
					break;
				}
			case 5:
				{break;
				}
			case 6:
				{break;
				}
			default:
				{
				 std::cout << "Please enter the correct option.";
				 break;
				}
				
			}	
	  }while(input != 5);	



	return(0);
}

void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack 1\n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}
