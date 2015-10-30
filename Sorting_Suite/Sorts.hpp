//public methods

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
void Sorts<T>::mergeSort(T arr[], int size)
{
	//test
	int mid = size / 2;
	int rps = size - mid; //right part's size
	
	if(mid > 0)
	{	
		int* frontp = arr;
		int* midp = (arr + mid);
		
		mergeSort(frontp, mid);
		mergeSort(midp, rps);
		merge(frontp, midp, mid, rps);
		
		frontp = nullptr;
		midp = nullptr;
	}
		
	assert(Sorts<T>::isSorted(arr, size));
	
	
}


template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	bool m = false;
	quickSortRec(arr, 0, (size - 1), m);
	
	
}



template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	bool m = true;
	quickSortRec(arr, 0, (size -1), m);
		
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

	assert(Sorts<T>::isSorted(arr, size));
	
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


//private methods

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
	//a1 is the left side array
	//a2 is the right side array
	
	//size 1 is the left array's size
	//size 2 is the right array's size
	int temp[size1 + size2];
	int left = 0;
	int right = 0;
	int index = 0;
	
	while((left < size1) && (right < size2))
	{
		if(a1[left] <= a2[right])
		{
			temp[index] = a1[left];
			left++;
		}
		else
		{
			temp[index] = a2[right];
			right++;
		}
		index++;
	}
	
	while(left < size1)
	{
		temp[index] = a1[left];
		left++;
		index++;
	}
		
	while(right < size2)
	{
		temp[index] = a2[right];
		right++;
		index++;
	}
	
	for(int i = 0; i < (size1 + size2); i++)
		a1[i] = temp[i];

}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if(first < last)
	{
		int k = partition(arr, first, last, median);
		quickSortRec(arr, first, k , median);
		quickSortRec(arr, k + 1, last, median);
	
	}		
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	int m = first + (last - first)/2;
	
	//swap
	int temp = arr[last];
	arr[last] = arr[m];
	arr[m] = temp;
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{	
	if(median == false)
	{
		int p = last;
		int l = first;
		int r = last - 1;

		while(l < r)
		{
			
			while(arr[l] < arr[p])
			{
				if( l == r)
					break;
				else
				{	
					l++;
				}
				
				
			}
			while(arr[r] > arr[p])
			{
				if( r == l)
					break;
				else
				{	
					r--;
				}
			}
		
			if(arr[l] == arr[r])
			{
				l++;
			}
			else if(l < r)
			{
				int temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
				
			}
		}
		
		if(arr[r] > arr[p])
		{
			int temp = arr[p];
			arr[p] = arr[r];
			arr[r] = temp;
		}
	
		return r;
	}
	else //median is true
	{
		setMedianPivot(arr, first, last); //arr[m] becomes arr[last]
		int p = last;
		int l = first;
		int r = last - 1;

		while(l < r)
		{
			while(arr[l] < arr[p])
			{
				if( l == r )
					break;
				else	
					l++;
			}
			while(arr[r] > arr[p])
			{
				if( r == l )
					break;
				else
					r--;
			}
		
			if(arr[l] == arr[r])
			{
				if( l == r )
					break;
				l++;
			}
			else if(l < r)
			{
				int temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
				if(l + 1 == r)
					break;
			}
		}
		
		if(arr[r] > arr[p])
		{
			int temp = arr[p];
			arr[p] = arr[r];
			arr[r] = temp;
		}
	
		
		return r;		
	}
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








