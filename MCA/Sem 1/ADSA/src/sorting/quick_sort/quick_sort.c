#include <stdio.h>
#include <stdlib.h>

#define DEBUG_ENABLED 1


// forward declarations
char* arr_str(const int, const int, const int*);
void print_array(const int*, const int);
void swap(const int, const int, int*);
int partition(const int, const int, int*);
void quick_sort(const int, const int, int*);


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

void quick_sort(const int l, const int h, int* arr)
{
	if(DEBUG_ENABLED)
		printf("  // Entered quick_sort(...) \n");
		
	if(l < h) {
		if(DEBUG_ENABLED) {
			char *s;
			printf("  // quick_sort:: l=%d, h=%d, arr: %s \n", l, h, s=arr_str(l, h, arr));
			free(s);
		}

		int p = partition(l, h, arr);

		if(DEBUG_ENABLED) {
			printf("  // quick_sort:: partition index: %d \n", p);
		}

		quick_sort(l, p-1, arr);
		quick_sort(p+1, h, arr);
	} 
}

int partition(const int l, const int h, int* arr) 
{
	if(DEBUG_ENABLED)
		printf("  // Entered partition(...) \n");

	int pivot = arr[l]; // considering first element in sub-array as pivot
	int i=l+1;
	int j=h;

	if(DEBUG_ENABLED) {
		char *s;
		printf("  // partition:: l=%d, h=%d, arr: %s, pivot=%d, i=%d, j=%d \n", l, h, s=arr_str(l, h, arr), pivot, i, j);
		free(s);
	}

	while(1) {
		if(DEBUG_ENABLED) {
			printf("  // while loop: i=%d, j=%d, (arr[i] <= pivot && i < j)=%d, (arr[j] > pivot)=%d \n", i, j, (arr[i] <= pivot && i < j), (arr[j] > pivot));
		}
		
		while(arr[i] <= pivot && i < j) {			
			i++;
			if(DEBUG_ENABLED)
				printf("  // i++ (i=%d) \n", i);
		}
		while(arr[j] > pivot) {
			j--;
			if(DEBUG_ENABLED)
				printf("  // j-- (j=%d) \n", j);
		}

		if(i < j) {
			swap(i, j, arr); 

			if(DEBUG_ENABLED) {
				char *s;
				printf("  // partition:: swap in middle; after swap: i=%d, j=%d, arr: %s \n", i, j, s=arr_str(l, h, arr));
				free(s);
			}
		} else 
			break;
	}

	swap(l, j, arr);

	if(DEBUG_ENABLED) {
		char *s;
		printf("  // partition:: setting pivot at j=%d; after swap: i=%d, j=%d, arr: %s \n", j, i, j, s=arr_str(l, h, arr));
		free(s);
	}

	return j; // pivot index
}

void swap(const int i, const int j, int* arr)
{
	if(DEBUG_ENABLED)
		printf("  // Entered swap(...) \n");
		
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

// DEBUG 
char* arr_str(const int l, const int h, const int* arr) 
{
	if(DEBUG_ENABLED)
		printf("  // Entered arr_str(...) \n");

	int strlen = 2*(h-l)+2+1;
	char* str = (char*) malloc(strlen * sizeof(char));

	str[0] = '[';
	int i, j;
	for(i=l, j=1; i<=h; i++, j++) {
		str[j++] = '0' + arr[i];
		str[j] = ',';
	}
	str[--j] = ']';
	str[++j] = 0;

	return str;
}

void print_array(const int* arr, const int len) 
{
	if(DEBUG_ENABLED)
		printf("  // Entered print_array(...) \n");
		
	int i;
	for(i=0; i<len; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}