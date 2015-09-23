#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Test.h"

void printMenu(); // print Menu; defination placed below main()

int main()
{
	int input = 0; // intput for the menu
	int node_int = 0; // a value to add to the node. The number will be determined by the user.

	LinkedList L2; // construct a linked-list

	do{		
	printMenu();
	std::cin >> input;
	std::cout << "You choose: " << input;
	switch(input)
	{
		case 1: {
			// add to the front
			std::cout << "\nInput a value to add:";
			std::cin >> node_int;
			std::cout << " Adding " << node_int << " to the list";
			L2.addFront(node_int);
			break;
			}		

		case 2: {
			 // add to the end
			std::cout << "\nInput a value to add:";
			std::cin >> node_int;
			std::cout << "\nAdding " << node_int << " to the list";
			L2.addBack(node_int);
			break;
			}

		case 3: {
			// remove from the front
			L2.removeFront();
			break;
			}

		case 4: {
			 // remove from the back
			L2.removeBack();
			break;
			}

		case 5: {
			// print the list
			std::cout << "\nPrint list:";
			L2.printList();
			break;
			}

		case 6: {
			// search for value
			std::cout << "\nEnter a value to search for:";
			int search = 0;
			std::cin >> search;
			std::cout << "\nSearching for " << search << " ...";	
			if(L2.search(search))
				std::cout << "\n" << search << " is in the list";
			else
				std::cout << "\n" << search << " is not in the list";
			break;
			}

		case 7: {
			// exit
			std::cout << "\nExit ...\n";	
			break;
			}

		case 8: {
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
	}
	}while(input != 7);


return 0;
}

void printMenu() // options for testing Linked-List
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "Enter your choice: ";
}
