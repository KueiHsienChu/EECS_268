#include "Sorts.h"
#include <iostream>
#include "Test.h"

void printMenu();

int main()
{

	int sort_choice = 0;
	int size = 0;
	int lower_bound = 0;
	int upper_bound = 0;
	bool keep_testing = true;
	std::string print_unsorted;
	std::string print_sorted;
	std::string run_loop; //run the whole thing or not
	double sort_seconds = 0.0;

	while(keep_testing == true)
	{
		printMenu();
		std::cin >> sort_choice;
		std::cout << "\nInput a size for the random array:";
		std::cin >> size;
		std::cout << "\nInput a lower bound on the range of random numbers:";
		std::cin >> lower_bound;
		std::cout << "\nInput an upper bound on the range of random numbers:";
		std::cin >> upper_bound;

		//create the array
		int* array1 = Sorts<int>::createTestArray(size, lower_bound, upper_bound);
 
		//print unsorted array
		std::cout << "\nDo you want to print the unsorted array? (y/n)";
		std::cin >> print_unsorted;
		if(print_unsorted == "y" || print_unsorted == "Y")
		{
			std::cout << "\n[ ";
			for(int i = 0; i < size; i++)
			{
				if(i == size - 1)
					std::cout << array1[i] << " ";
				else
					std::cout << array1[i] << ", ";
			}//end for
					
			std::cout << " ]";
		}
		
		//start sorting
		if(sort_choice == 1)
		{
			std::cout << "Starting bubble sort.\n";
			sort_seconds = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array1, size);
			std::cout << size << " numbers were sorted in " << sort_seconds << " seconds";
		}

		//continue the test or not
		std::cout << "\nDo you want to quit? (y/n)";
		std::cin >> run_loop;
		if(run_loop == "n" || run_loop == "N")
			keep_testing = true;
		else
			keep_testing = false; 
		
		
		//prevent memory leaks
		delete[] array1;
		
	}//end while
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
