#include "Stack.h"
#include "Test.h"
#include <iostream>

void printMenu(); //Menu


int main()
{
	int input = 0; //User input
	int value = 0; //User value input
	StackInterface<int>* pile1 = new Stack<int>();
	int top_stack_value = 0;//This will be the top value recoded after each run of the switch menu --(bottom of do/while)
	
	do{
		printMenu();
		std::cin >> input;
		std::cout << "\n" << "You chose: " << input << std::endl;
		switch(input)
		{
			case 1:
				{
					std::cout << "What is going in Stack 1? ";	
					std::cin >> value;
					pile1 -> push(value);
					std::cout << "\n" << value << " successfully added to stack 1";
					break;
				}
			case 2:
				{
					try
					{
						std::cout << pile1 -> peek() << " is at the top of stack 1";
						
					}
					catch(std::exception& e)
					{
						std::cout << "Exception: " << e.what();
					}
					break;
				}
			case 3:
				{	
					pile1 -> print();
					break;
				}
			case 4:
				{
					try
					{
						pile1 -> pop();
						std::cout << top_stack_value << " removed from stack 1";
						
					}
					catch(std::exception& e)
					{
						std::cout << "Exception: " <<  e.what();
					}
					break;
				}
			case 5:
				{
					std::cout << "Program ending\n";
					break;
				}
			case 6:
				{
					Test myTester(std::cout);
					myTester.runTests();
					break;
				}
			default:
				{
					 std::cout << "Please enter the correct option.";
					 break;
				}
				
			}

		//Top value of the stack after each round	
		if(pile1 -> size() > 0)
			top_stack_value = pile1 -> peek();

	  }while(input != 5);	

	//delete StackInterface
	delete pile1;
	pile1 = nullptr;

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
