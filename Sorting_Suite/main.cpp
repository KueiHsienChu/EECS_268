#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"


int main(int argc, char** argv)
{
	bool problem = false;
	//Verifies there are at least 2 command line arguments
	if(argc < 2)
		problem = true;
	/*Verifies the first parameter is either "-create" (for number file generation) 
	"-sort" (for sort timing) or "-test" (for running the test suite)*/
	else if(argv[0] != "-create" || argv[0] != "-sort" || argv[0] != "-test")
		problem = true; 
	//Prints the help menus from both the NumberFileDriver and SortDriver class when problem is detected
	if(problem == true)
		
	/*If at least 2 command line arguments are passed in and the user chose to "-create", 
	"-sort", or "-test" the argc and argv are then passed to the appropriate run method.*/





/*
	//test!!! for my merge sort
	int size = 10;
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


	std::cout << " ]\n\n";

	std::cout << "Finished printing created array\n";
			
	sort_seconds = Sorts<int>::sortTimer(Sorts<int>::mergeSort, array1, size);
	
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

*/
return 0;
}


