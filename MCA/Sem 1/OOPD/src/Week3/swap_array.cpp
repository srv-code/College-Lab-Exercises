// Author name: Sourav Dey
// Date of creation: 13-Aug-2018
// Week number: 3
// Program name:  To swap the contents of two single dimension integer arrays

#include <iostream>

#include <cstdlib> // Remove 

using namespace std;

void print_array(const int* arr, const int size)
{
	for(int i=0; i<size; i++)
		cout << "  [" << i << "]  " << arr[i] << "\n";
	cout << endl;
}

void swapArray(int* arr1, int* arr2, const int size)
{
	for(int i=0, temp; i<size; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

int main() 
{
	const int ARRAY_SIZE = 5;
	int arr1[ARRAY_SIZE], arr2[ARRAY_SIZE];
	system("clear");
	
	for(int array_no = 1; array_no <= 2; array_no++)
	{
		cout << "\nEnter " << ARRAY_SIZE << " elements for array " << array_no << ": \n";
		for(int i=0; i<ARRAY_SIZE; i++)
		{
			cout << "\t Enter element at " << i << ": ";			
			if(array_no == 1)
				cin >> arr1[i];
			else 
				cin >> arr2[i];				
		}
	}
	
	cout << "\nBefore swapping: \n";
	cout << "\t Array1:\n";
	print_array(arr1, ARRAY_SIZE);
	cout << "\t Array2:\n";
	print_array(arr2, ARRAY_SIZE);
	
	swapArray(arr1, arr2, ARRAY_SIZE);
	
	cout << "\nAfter swapping: \n";
	cout << "\t Array1:\n";
	print_array(arr1, ARRAY_SIZE);
	cout << "\t Array2:\n";
	print_array(arr2, ARRAY_SIZE);
	
	
	return 0;
}