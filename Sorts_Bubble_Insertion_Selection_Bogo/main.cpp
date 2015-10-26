#include "Sorts.h"
#include <iostream>
#include "Test.h"

void printMenu();

int main()
{

	int sort_choice = 0;
	int size = 0; //size for the array (e.g. 5 -> 0,1,2,3,4)
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
		if(sort_choice != 5)
		{
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
				std::cout << "\nHere is the unsorted array:\n[ ";
				//display array
				for(int i = 0; i < size; i++)
				{
					if(i == size - 1)
						std::cout << array1[i] << " ";
					else
						std::cout << array1[i] << ", ";
				}//end for
						
				std::cout << " ]\n\n";
			}
			//start sorting
			if(sort_choice == 1)
			{
				std::cout << "Starting bubble sort.\n";
				sort_seconds = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array1, size);
			}
			else if(sort_choice == 2)
			{
				std::cout << "Starting insertion sort.\n";
				sort_seconds = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array1, size);
			}	
			else if(sort_choice == 3)
			{
				std::cout << "Starting selection sort.\n";
				sort_seconds = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array1, size);
			}	
			else if(sort_choice == 4)
			{
				std::cout << "Starting bogo sort.\n";
				sort_seconds = Sorts<int>::sortTimer(Sorts<int>::bogoSort, array1, size);
			}
			//print sorted array
			std::cout << "\nDo you want to print the sorted array? (y/n)";
			std::cin >> print_sorted;
			if(print_sorted == "y" || print_sorted == "Y")
			{
				std::cout << "\nHere is the sorted array:\n[ ";
				//display array
				for(int i = 0; i < size; i++)
				{
					if(i == size - 1)
						std::cout << array1[i] << " ";
					else
						std::cout << array1[i] << ", ";
				}//end for
						
				std::cout << " ]\n\n";
			}
			
			std::cout << size << " numbers were sorted in " << sort_seconds << " seconds\n";

			//continue the test or not
			std::cout << "\nDo you want to quit? (y/n)";
			std::cin >> run_loop;
			if(run_loop == "n" || run_loop == "N")
				keep_testing = true;
			else
				keep_testing = false; 
			
			
			//prevent memory leaks
			delete[] array1;
			

		}
		if(sort_choice == 5)
		{
			Test myTester(std::cout); //declares a Test instance

			myTester.runTests(); //runs a series of tests on your code
		}					
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
			<< "5) TEST SUITE RUN\n"
			<< "Enter choice: ";
}
