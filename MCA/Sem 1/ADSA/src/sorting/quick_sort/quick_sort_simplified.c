#include <stdio.h>
#include <stdlib.h>


void swap(const int i, const int j, int* arr)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void print_array(const int* arr, const int len) 
{
	int i;
	for(i=0; i<len; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

int partition(const int l, const int h, int* arr) 
{
	int pivot = arr[l]; // considering first element in sub-array as pivot
	int i=l+1;
	int j=h;

	while(1) {
		while(arr[i] <= pivot && i < j) 
			i++;
		while(arr[j] > pivot)
			j--;

		if(i < j)
			swap(i, j, arr); 
		else
			break;
	}

	swap(l, j, arr);
	return j; // pivot index
}

void quick_sort(const int l, const int h, int* arr)
{
	if(l < h) {
		int p = partition(l, h, arr);
		quick_sort(l, p-1, arr);
		quick_sort(p+1, h, arr);
	} 
}


int main() 
{
	system("clear");

	int len;
	printf("Input array length:  ");
	scanf("%d", &len);

	int arr[len];

	printf("Input array elements: \n");
	int i;
	for(i=0; i<len; i++) {
		printf("  [%d]:  ", i);
		scanf("%d", &arr[i]);
	}

	printf("Array:  ");
	print_array(arr, len);
	
	printf("Applying quick sort... \n");
	quick_sort(0, len-1, arr);

	printf("Array:  ");
	print_array(arr, len);


	return 0;
}