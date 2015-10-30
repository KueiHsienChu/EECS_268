#include "SortDriver.h"

void SortDriver::run(int argc, char** argv)
{
	//argument is at 2nd position in argv. (0, 1, 2, ..)
	//argv:
	//0 -- program 
	//1 -- argument for functions
	//2 -- sort method
	//3 -- filename
	//4 -- inputfile
	//5 -- outputfile

	std::string sortm = argv[2];
	std::string filename = argv[3];
	
	if(areParametersValid(sortm, filename))
	{
		
		int num_elements;
		std::string outfileName = argv[5];

		std::ifstream read(filename);
		num_elements = getFileCount(read);
	
		int* array = createArray(read, num_elements);

		
		std::ofstream write(outfileName);
		double sort_time;
				
		if(sortm == "-bubble")
		{	
			sort_time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array, num_elements);
			write << "bubble " << num_elements << " " << sort_time;
		}
		else if(sortm == "-insertion")
		{
			sort_time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array, num_elements);
			write << "insertion " << num_elements << " " << sort_time;
		}
		else if(sortm == "-selection")
		{
			sort_time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array, num_elements);
			write << "selection " << num_elements << " " << sort_time;
		}
		else if(sortm == "-merge")
		{
			sort_time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, array, num_elements);
			write << "merge " << num_elements << " " << sort_time;
		}
		else if(sortm == "-quick")
		{
			sort_time = Sorts<int>::sortTimer(Sorts<int>::quickSort, array, num_elements);
			write << "quick " << num_elements << " " << sort_time;
		}
		else if(sortm == "-quick3")
		{
			sort_time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, array, num_elements);
			write << "quick3 " << num_elements << " " << sort_time;
		}
		else if(sortm == "-all")
		{
		}	
	}
	else
	{
		printHelpMenu();
	}
}

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}

bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream read(fileName);
	
	if(read.good())
		return true;
	else
		return false;

}

bool SortDriver::isSortValid(std::string sortParameter)
{
	if( sortParameter == "-bubble")
		return true;
	else if( sortParameter == "-insertion")
		return true;
	else if( sortParameter == "-selection")
		return true;
	else if( sortParameter == "-merge")
		return true;
	else if( sortParameter == "-quick")
		return true;
	else if( sortParameter == "-quick3")
		return true;
	else if( sortParameter == "-all")
		return true;
	else
		return false;
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(isSortValid(sortName) && isFileAccessible(inputFileName))
		return true;
	else
		return false;
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	std::string str;
	inputFile >> str;
	return(std::stoi(str)); 
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{	
	std::string word;
	int* create = new int[size];
	for(int i = 0; i < size; i++)
	{
		inputFile >> word;
		create[i] = std::stoi(word);
	}	

	return create;
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
}


