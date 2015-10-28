#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char** argv)
{
	std::string option_ = argv[2];
	//argument is at 2nd position in argv. (0, 1, 2, ..)
	//argv:
	//0 -- program 
	//1 -- argument for functions
	//2 -- order of the array
	//3 -- filename
	//4 -- amount
	//5 -- value (for -s) min (for-r)
	//6 -- max (for -r)
	
	if(isValidOption(option_))
	{
		//write to file
		
		if(argument == "-a" && argc == 5)
			NumberFileGenerator::ascending(argv[3], std::stoi(argv[4]));

		else if(argument == "-d" && argc == 5)
			NumberFileGenerator::descending(argv[3], std::stoi(argv[4]));

		else if(argument == "-s" && argc == 6)
			NumberFileGenerator::singleValue(argv[3], std::stoi(argv[4]), std::stoi(argv[5]));

		else if(argument == "-r" && argc == 7)
			NumberFileGenerator::random(argv[3], std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6]));
		else
			printHelpMenu();
		
	}
	
	

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
	if(option == "-a" || option == "-d" || option == "-s" || option == "-r")
		return true;
	else
	{
		printHelpMenu();
		return false;
	}			
}
