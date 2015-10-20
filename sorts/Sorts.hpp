template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
}

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	//Declare and seed a generator
	std::default_random_engine generator(time(nullptr));

	//Declare a distribution and define the range of the random numbers
	std::uniform_int_distribution<int> distribution(min, max);
	
	//Generate an array filled with random number
	int* temp = new int[size];
	for(int i = 0; i < size; i++)
	{
		temp[i] = distribution(generator);
	}

	return(temp);

}

template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	
}


