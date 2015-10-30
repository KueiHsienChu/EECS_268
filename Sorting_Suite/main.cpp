#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"
#include "Test.h"
#include <iostream>


int main(int argc, char** argv)
{

	for(int i = 0; i < argc; i++)
		std::cout << argv[i] << " ";

	//Verifies there are at least 2 command line arguments
	/*Verifies the first parameter is either "-create" (for number file generation) 
	"-sort" (for sort timing) or "-test" (for running the test suite)*/
	//Prints the help menus from both the NumberFileDriver and SortDriver class when problem is detected
	/*If at least 2 command line arguments are passed in and the user chose to "-create", 
	"-sort", or "-test" the argc and argv are then passed to the appropriate run method.*/


	if(argc >= 2)
	{
		std::string mode = argv[1];
		

		if(mode == "-create" || mode == "-sort" || mode == "-test")
		{
			

			Test test(std::cout);

			//Check for number file creation flag
			if(mode == "-create")
			{
				NumberFileDriver::run(argc, argv);		
			}

			//Check for sort flag
			else if (mode == "-sort")
			{
				SortDriver::run(argc, argv);
			}

			//Check for test flag
			else if (mode == "-test")
			{
				test.runTests();
			}	
		}
		else
		{
			NumberFileDriver::printHelpMenu();
			SortDriver::printHelpMenu();
		}
	}
	else
	{	
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();
	}

/*

	//test!!! for my merge sort
	int size = 6;
	double sort_seconds = 0.0;
	int* array1 = Sorts<int>::createTestArray(size,0 ,50);
	
	std::cout << "\nHere is the unsorted array:\n[ ";
				//display array	
	for(int i = 0; i < size; i++)
	{
		if(i == size - 1)
			std::cout << array1[i] << " ";
		else
			std::cout << array1[i] << ", ";
	}//end for

	int* a = new int[5];
	a[0] = 13;
	a[1] = 37;
	a[2] = 3;
	a[3] = 37;
	a[4] = 35;
	std::cout << " ]\n\n";

	std::cout << "Finished printing created array\n";
			
	sort_seconds = Sorts<int>::sortTimer(Sorts<int>::quickSort, array1, size);
	
	std::cout << "\nHere is the sorted array:\n[ ";	
	for(int i = 0; i < size; i++)
	{
		if(i == size - 1)
			std::cout << array1[i] << " ";
		else
			std::cout << array1[i] << ", ";
	}//end for
	std::cout << " ]\n\n";				
	//end test!!
	delete a;
	delete array1;
	a = nullptr;
	array1= nullptr;
*/
return 0;
}


