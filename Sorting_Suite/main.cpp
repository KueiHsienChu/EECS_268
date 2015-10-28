#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"


int main(int argc, char** argv)
{
	
	NumberFileDriver::run(argc, argv);


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


