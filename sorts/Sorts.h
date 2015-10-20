#ifndef SORT_H
#define SORT_H


template <typename T>

class Sorts
{
	public:
		/*
		@pre:
		@post: sorts arr using bubble sort algorithm
		*/
		static void bubbleSort(T arr[], int size);
		/*
		@pre:
		@post: sorts arr using bogo sort algorithm 
		*/
		static void bogoSort(T arr[], int size);
		/*
		@pre:
		@post: sorts arr using insertion sort algorithm 
		*/
		static void insertionSort(T arr[], int size);
		/*
		@pre:
		@post: sorts arr using selection sort
		*/
		static void selectionSort(T arr[], int size);
		/*
		@pre:
		@post: returns true is arr is in ascending order, false otherwise
		*/
		static bool isSorted(T arr[], int size);
		/*
		@pre:
		@post: For each index in the array, swap it the value at another random index
		*/
		static void shuffle(T arr[], int size, std::default_random_engine& generator);
		/*
		@pre:
		@post: creates a new array of the specified size and contains random values 
		       that fall within the range specified by min and max (inclusive) not responsible for deleting the array
		*/
		int* createRandomIntArray(int size, int min, int max);
		/*
		@pre:
		@post: 	arr is a vaild array of T of size elements, and the < operator is 
			overloaded for T. sort must be capable of sorting arr in ascending order,
			or an assert will end the program. after running, arr is sorted in ascending 
			order returns the time, in seconds, the sort required to sort arr.
		*/
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);


};


#endif
