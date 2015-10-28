#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

#include <iostream>
#include "NumberFileGenerator.h"

class NumberFileDriver
{
	public:
		/*
		@pre: preconditions: arguments is a valid 2-D array and the arguments contained within are valid. 
			**The argc and argv should be passed directly from main**
		@post: post conditions: If the arguments are valid, a number file is created following those 
			specifications. Otherwise, the help menu is printed and no files are created. 
		@returns: None. 
		*/
		static void run(int argc, char** argv); 

		/*
		@pre:
		@post: 
		*/
		static void printHelpMenu(); 

	private:
		static bool isValidOption(std::string option); 
		//preconditionsNone.
		//post conditions Prints a menus to help the user use the NumberFileGenerator
		//returns True is the option passed in is valid. Valid options are: "-a", "-d", "-r", and "-s". This is case sensitive.


};

#endif
