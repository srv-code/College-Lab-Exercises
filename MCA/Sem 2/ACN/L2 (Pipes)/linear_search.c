/*  
	Write a program to perform Linear Search
    using pipes and fork () system calls.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int linear_search(	const int arr[], 
					const int start, 
					const int end, 
					const int tgt) {
	for(int i=start; i<end; i++)
		if(arr[i] == tgt)
			return i-start;
	return -1; // element not found
}

int main(const int argc, const char *argv[]) {
	/* 6)	Write a program to perform Linear Search using pipe() and fork() system calls. */
	int fd1[2], fd2[2];
	
	if(pipe(fd1) == -1 || pipe(fd2) == -1) {
		fprintf(stderr, "Err: Unable to create pipes! \n");
		return 1;
	}
	
	int status = fork();
	
	if(status == -1) {
		fprintf(stderr, "Err: Unable to fork! \n");
		return 2;
	}
	
	if(status == 0) {
		// child proc: acts as server
		close(fd1[1]);
		const int ARR_SIZE = 100;
		int arr[ARR_SIZE];
		read(fd1[0], arr, ARR_SIZE);
		close(fd1[0]);
		
		int size=arr[0];
		int tgt=arr[1];
		
		close(fd2[0]);
		int idx = linear_search(arr, 2, size, tgt);
		write(fd2[1], &idx, sizeof(int));
		close(fd2[1]);
	} else {
		// parent proc: acts as client
		close(fd1[0]);
		int size;
		printf("Enter array size:  ");
		scanf("%d", &size);
		size += 2;
		int arr[size]; // first element: size, second element: tgt, rest: arr elements
		printf("Enter array elements: \n");
		for(int i=2; i<size; i++) {
			printf("  Element %d:  ", i-1);
			scanf("%d", &arr[i]);
		}
		printf("Enter search element:  ");
		int tgt;
		scanf("%d", &tgt);
		arr[0] = size;
		arr[1] = tgt;
		
		write(fd1[1], arr, sizeof(int)*size);
		close(fd1[1]);
		
		int idx;
		close(fd2[1]);
		read(fd2[0], &idx, sizeof(int));
		close(fd2[0]);
		
		if(idx == -1) {
			printf("Result: Search element not found! \n");
		} else {
			printf("Result: Search element found at index %d \n", idx);
		}
	}
	
	return 0;
}