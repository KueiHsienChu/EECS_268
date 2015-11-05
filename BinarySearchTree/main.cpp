#include "BinarySearchTree.h"
#include "Test.h"
#include <climits>
#include <iostream>

void printMenu();

int main(int argc, char** argv)
{

	if(argc > 1)
	{
		std::string arg = argv[1];

		if(arg == "-test")
		{
			Test test;
			test.runTests();
		}
		else
		{
			int nums = std::stoi(argv[2]);
		
			std::random_device randomDevice;	
			std::default_random_engine generator(randomDevice());
			std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
		
			std::vector<int> vec;
			int rand = 0;
			int numberAdded = 0;
		
			while(numberAdded < nums)
			{	
				rand = distribution(generator);
				vec.push_back(rand);
				numberAdded++;
			}
		}
			
	}
	
	BSTI<int>* bst = new BinarySearchTree<int>();
	bst->add(20);
	bst->add(22);
	bool test = bst->search(20);
	bool test2 = bst->search(22);
	std::cout << test << " " << test2;
	
	
	
	
	




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
