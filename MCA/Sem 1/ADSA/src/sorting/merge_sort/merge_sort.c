#include <stdio.h>
#include <stdlib.h>

#define DEBUG_ENABLED 0


// forward declarations
void merge(const int, int const, int const, int*);
void merge_sort(const int, const int, const int*); 
char* arr_str(const int, const int, const int*);
void print_array(const int*, const int);


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
	
	printf("Applying merge sort... \n");
	merge_sort(0, len-1, arr);

	printf("Array:  ");
	print_array(arr, len);


	return 0;
}


// Two way merge sort: iterative process
void merge(const int l, int const mid, int const h, int* arr) 
{
	// first array:  l to mid
	// second array: mid+1 to h

	int i, j, k, tarr_len = h-l+1, tarr[tarr_len];
	for(i=l, j=mid+1, k=0; i<=mid && j<=h; k++) {
		tarr[k] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	}

	if(i<=mid) {
		// fill from first array only 
		for(; i<=mid; i++, k++) {
			tarr[k] = arr[i];
		}
	} else if(j<=h) {
		// fill from second array only 
		for(; j<=h; j++, k++) {
			tarr[k] = arr[j];
		}
	}

	// copy back from the temp array to main array
	for(k=0, i=l; k<tarr_len; k++, i++)
		arr[i] = tarr[k];

	if(DEBUG_ENABLED) {
		char *s1, *s2;
		printf("  // merged (l=%d, m=%d, h=%d), tarr: %s, arr: %s \n", l, mid, h, s1=arr_str(0, tarr_len-1, tarr), s2=arr_str(l, h, arr));
		free(s1);
		free(s2);
	}
}

void merge_sort(const int l, const int h, const int* arr) 
{
	if(DEBUG_ENABLED) {
		char *s;
		printf("  // merge_sort: l=%d, h=%d, arr: %s \n", l, h, s=arr_str(l, h, arr));
		free(s);
	}

	if(l < h) {
		int mid = (l+h)/2;
		merge_sort(l, mid, arr);
		merge_sort(mid+1, h, arr);
		merge(l, mid, h, arr);
	}
}

// DEBUG 
char* arr_str(const int l, const int h, const int* arr) 
{
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
	int i;
	for(i=0; i<len; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

