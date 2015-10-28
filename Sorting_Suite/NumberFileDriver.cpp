#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char** argv)
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
		printHelpMenu();
		
	/*If at least 2 command line arguments are passed in and the user chose to "-create", 
	"-sort", or "-test" the argc and argv are then passed to the appropriate run method.*/


}

void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(std::string option)
{
}
