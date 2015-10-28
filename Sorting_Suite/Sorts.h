#ifndef SORT_H
#define SORT_H

#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>

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
		@post: creates a new array of the specified size and contains random values 
		       that fall within the range specified by min and max (inclusive) not responsible for deleting the array
		*/
		static int* createTestArray(int size, int min, int max);

		/*
		@pre:
		@post: sorts arr using mergeSort algorithm
		*/
		static void mergeSort(T arr[], int size);

		/*
		@pre:
		@post: Calls quickSort with median flag set to false 
		*/
		static void quickSort(T arr[], int size);

		/*
		@pre:
		@post: Calls quickSort with median flag set to true 
		*/
		static void quickSortWithMedian(T arr[], int size); 

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
		@post: 	arr is a vaild array of T of size elements, and the < operator is 
			overloaded for T. sort must be capable of sorting arr in ascending order,
			or an assert will end the program. after running, arr is sorted in ascending 
			order returns the time, in seconds, the sort required to sort arr.
		*/
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);

	private:
 
		static void merge(T* a1, T* a2, int size1, int size2);
		//used by merge sort to two sorted combine arrays 
		//(which are actually two halved of a single array) into a single sorted array

		static void quickSortRec(T arr[], int first, int last, bool median); 
		/*sorts the array by partitioning the array, quick sortingevery left of the pivot, and quick sorting 
		everything right of the pivot passes median to partition to inform that method how to pick a pivot value*/

		static void setMedianPivot(T arr[], int first, int last);
		//used by quickSort 
		//puts the median value of the array in the last position 
		//make sure not to lose any values in the process! 
		
		static int partition(T arr[], int first, int last, bool median);
		//used by quickSort 
		//partitions the array 
		/*chooses a pivot based on the median flag, if median is true, 
		use setMedianPivot, otherwise select the last element in the array*/
		//returns the index of the pivot 
		
		static void shuffle(T arr[], int size, std::default_random_engine& generator);
		//For each index in the array, swap it the value at another random index 

};

#include "Sorts.hpp" //damn I need to remember this crap 
#endif	
