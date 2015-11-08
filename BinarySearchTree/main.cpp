#include "BinarySearchTree.h"
#include "Test.h"
#include <climits>
#include <iostream>

void printMenu();

int main(int argc, char** argv)
{

	BSTI<int>* bst = new BinarySearchTree<int>(); //the original tree the user will interact with
	BSTI<int>* bst_clone = new BinarySearchTree<int>(); //the cloned tree

	std::vector<int> vec;
	int rand = 0;
	int numberAdded = 0;
	
	std::random_device randomDevice;	
	std::default_random_engine generator(randomDevice());
	std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

	if(argc == 2)
	{
		std::string arg = argv[1];

		if(arg == "-test")
		{
			Test test;
			test.runTests();
		}
		else
		{
			int nums = std::stoi(argv[1]);
		
			while(numberAdded < nums)
			{	
				rand = distribution(generator);
				vec.push_back(rand);
				numberAdded++;
			}//end while
		}//end else
			
		for(std::size_t i = 0; i < vec.size(); i++)
		bst->add(vec[i]);
	}
	
	if(argc == 3)
	{
		std::string arg = argv[1];
	
		if(arg == "-nodes")
		{	
			int nums = std::stoi(argv[2]);
	
			while(numberAdded < nums)
			{	
				rand = distribution(generator);
				vec.push_back(rand);
				numberAdded++;
			}//end while
		}
		
		for(std::size_t i = 0; i < vec.size(); i++)
		bst->add(vec[i]);
	}		
	
	


	
	int choice = 0; //choice for menu
	int value = 0; //value to add into the tree
	int delete_flag = 1; //use to check if original tree is deleted
	int choice_print = 0; //use for different print methods
	int search = 0; //search value
	
	do
	{
		printMenu();	
		std::cin >> choice;
	
		switch(choice)
		{
			case 1:	{
					std::cout << "Enter the value you want to store in the tree: ";
					std::cin >> value;
				
					bst->add(value);
				
					std::cout << "value add!\n";
					break;
				}

			case 2: {
					bst_clone = bst->clone();
					break;
				}
		
			case 3: {
					if(delete_flag == 1 && !(bst->isEmpty()))
					{
						delete bst;
						delete_flag = 0;
						bst = new BinarySearchTree<int>();
					}
					else if(delete_flag == 0)
						std::cout << "The delete flag is 0 thus no delete tree anymore\n";
					else
						std::cout << "The original tree is already empty.\n";
					break;
				}
	
			case 4:	{	
					if(bst->isEmpty())
						std::cout << "The tree is empty. Nothing to print.\n";
					else
					{
						std::cout << "Please choose an order: 1)Pre 2)In 3)Post --";
						std::cin >> choice_print;
						if(choice_print == 1)
							bst->printTree(PRE_ORDER);
						else if(choice_print == 2)
							bst->printTree(IN_ORDER);
						else if(choice_print == 3)
							bst->printTree(POST_ORDER);
						
						std::cout << "\n";
					}
					break;
				}
		
			case 5: {	if(bst_clone->isEmpty())
						std::cout << "The copy tree is empty. Nothing to print.\n";
					else
					{
						std::cout << "Please choose an order: 1)Pre 2)In 3)Post --";
						std::cin >> choice_print;
						if(choice_print == 1)
							bst_clone->printTree(PRE_ORDER);
						else if(choice_print == 2)
							bst_clone->printTree(IN_ORDER);
						else if(choice_print == 3)
							bst_clone->printTree(POST_ORDER);
						std::cout << "\n";
					}
					break;
				}
		
			case 6: {
					std::cout << "Input the value you want to search: ";
					std::cin >> search;
					if(bst->search(search))
						std::cout << "The value " << search << " is found in the tree!\n";
					else
						std::cout << "The value " << search << " is NOT found in the tree!\n";
					break;
				}
		
			case 7: {
					std::cout << "Input the value you want to search: ";
					std::cin >> search;
					if(bst_clone->search(search))
						std::cout << "The value " << search << " is found in the tree!\n";
					else
						std::cout << "The value " << search << " is NOT found in the tree!\n";
					
					break;
				}
	
			case 8: {
					choice = 10; //exit
					break;
				}
		
			case 9: {
					Test test;
					test.runTests();
					break;
				}
		
			default: {
					std::cout << "Please enter a valid choice";
					break;
				 }
		}//end switch
	
	

	}while(choice < 10 && choice > 0); //end switch

	delete bst;
	delete bst_clone;
	bst = nullptr; bst_clone = nullptr;

	return 0;
}

void printMenu()
{
	std::cout 	<< "Input a selection \n"
			<< "1) Add more values to original tree \n"
			<< "2) Copy the original tree \n"
			<< "3) Delete the original tree (one time only) \n"
			<< "4) Print original tree \n"
			<< "5) Print copy \n"
			<< "6) Search original tree \n"
			<< "7) Search copy \n"
			<< "8) Exit \n"
			<< "9) Run tests \n"
			<< "Your choice:  \n";
}
