template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
	for(int j = 0; j < size - 1; j++)
	{
		for(int i = 0; i < size - 1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}

	assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
  	//Declare and seed a generator
	std::default_random_engine generator;
	
	while(!isSorted(arr, size))
		shuffle(arr, size, generator); 	

	assert(Sorts<T>::isSorted(arr, size));
	
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	int j;

	for(int i = 1; i < size; i++)
	{
		j = i;
		
		while(j > 0 && arr[j - 1] > arr[j])
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}

}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		int smallest = arr[i];
		int tracked = i; //the I(th) element 
		
		for(int j = i; j < size - 1; j++)
		{
			if(j != size -1)
			{
				if(arr[j+1] < smallest)
				{
					smallest = arr[j+1];
					tracked = j + 1;
				}
			}
			
		}
		
		arr[tracked] = arr[i];
		arr[i] = smallest;
		//so if I(th) element is the smallest, it swap itself;
	}
					
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	bool sorted = true;
	for(int j =0; j < size -1; j++)
	{
		if(arr[j] > arr[j + 1])
			sorted = false;	
	}//end for
	
	return(sorted);
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{	
	int temp_arr_label;
	int temp_value;
	

	std::uniform_int_distribution<int> distribution(0, size - 1);

	for(int i = 0; i < size; i++)
	{
		temp_arr_label = distribution(generator);
		temp_value = arr[i];
		arr[i] = arr[temp_arr_label];
		arr[temp_arr_label] = temp_value;
	} 

		
		
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
	//elasped is a built-in variable (type double)	
	
	//Declarations	
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	//Timing something
	start = std::chrono::system_clock::now();
	
	//Do what you want to time
	sort(arr, size);
	end = std::chrono::system_clock::now();
	elapsed = (end - start);

	double time = elapsed.count();
	return(time);	
}


