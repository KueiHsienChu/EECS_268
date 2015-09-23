#include "DoubleLinkedList.h"
#include <stdexcept>
#include <iostream>
#include "Test.h" 

void printMenu(); //menu

int main()
{
	int user_input = 0;
	int user_add = 0;
	int user_pick = 0;	
	
	DoubleLinkedList<int> L2;
	
	do{		
	printMenu();
	std::cin >> user_input;
	std::cout << "You choose: " << user_input;
	switch(user_input)
	{
		case 1: {
			// push to the front
			std::cout << "\nInput a value to add:";
			std::cin >> user_add;
			std::cout << "\n" << user_add << "added to front of the list";
			L2.pushFront(user_add);
			break;
			}		

		case 2: {
			 // add to the end
			std::cout << "\nInput a value to add:";
			std::cin >> user_add;
			std::cout << "\n" << user_add << "added to back of the list";
			L2.pushBack(user_add);
			break;
			}

		case 3:	{
		       	 // insert a value from behind
			std::cout << "\nGive a value to insert";
			std::cin >> user_add;
			std::cout << "\nPick a value to insert behind";
			std::cin >> user_pick;
			std::cout << "\nAttempting to insert " << user_add << " behind " << user_pick;

			try
				{
					L2.insertBehind(user_pick, user_add);
				}
			catch(std::exception& e) //handles exceptions		
				{	
					std::cout << e.what(); 
				}
			break;
			}

		case 4:	{
			 // insert a value from the front
			std::cout << "\nGive a value to insert";
			std::cin >> user_add;
			std::cout << "\nPick a value to insert ahead of";
			std::cin >> user_pick;
			std::cout << "\nAttempting to insert " << user_add << " ahead " << user_pick;

			try
				{
					L2.insertAhead(user_pick, user_add);
				}
			catch(std::exception& e) //handles exceptions			
				{
					std::cout << e.what(); 
				}
			break;
			}

		case 5: {
			// remove from the front
			L2.removeFront();
			break;
			}

		case 6: {
			 // remove from the back
			L2.removeBack();
			break;
			}

		case 7: {
			// remove specific value
			std::cout << "\nEnter a value to remove:";
			std::cin >> user_pick;
			std::cout << "\nYou gave " << user_pick;	
			if(L2.remove(user_pick))
				std::cout << "\n" << user_pick << " removed from list";		
			else
				std::cout << "\n" << user_pick << " not removed from list";		
			break;
			}

		case 8: {
			// print the list
			std::cout << "\nPrint list:";
			L2.printList();
			break;
			}

		case 9: {
			// exit
			std::cout << "\nExit ...\n";	
			break;
			}

		case 10: {
			//Test
			Test myTester(std::cout); //declares a Test instance

			myTester.runTests(); //runs a series of tests on your code
				//end Test
			break;
			}
		default:{
			std::cout << "\nInvalid choice";
			break;
			}
	}//end switch
	}while(user_input != 9);


return 0;
}

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}
