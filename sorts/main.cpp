#include "Sorts.h"
#include <iostream>
#include "Test.h"

void printMenu();

int main()
{

	int size = 0;
	int lower_bound = 0;
	int upper_bound = 0;
	bool keep_testing = true;
	std::string print_unsorted;
	std::string print_sorted;

	while(keep_testing == true)
	{
		printMenu();
		std::cout << "Input a size for the random array:";
		std::cin >> size;
		std::cout << "\nInput a lower bound on the range of random numbers:";
		std::cin >> lower_bound;
		std::cout << "\nInput an upper bound on the range of random numbers:";
		std::cin >> upper_bound;

		//create the array
		int* sort = Sorts<int>::createTestArray(size, lower_bound, upper_bound);
 
		//print unsorted array
		std::cout << "\nDo you want to print the unsorted array?";
		std::cin >> print_unsorted;
		if(print_unsorted == "y" || print_unsorted == "Y")
		{
			std::cout << "\n[ ";
			for(int i = 0; i < size; i++)
				std::cout << sort[i] << ", ";
			std::cout << " ]";
		}
				
		
		
		
	}
	return 0;
}



void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}
