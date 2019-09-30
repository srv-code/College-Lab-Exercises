#include <stdio.h>

const int 	MAX_MATRIX_SIZE = 20;

int main() 
{
	int	matrix_orig[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], 
		matrix_rebuilt[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],		
		array_1d[MAX_MATRIX_SIZE],
		matrix_sz, r, c;

	system("clear");

	printf("Enter matrix size: ");
	scanf("%d", &matrix_sz);

	printf("Enter elements in matrix (%d x %d): \n", matrix_sz, matrix_sz);
	for(r = 0; r < matrix_sz; r++)
	{
		printf("  Row %2d: \n", r);
		for(c = 0; c < matrix_sz; c++)
		{
			printf("    Column %2d: ", c);
			scanf("%d", &matrix_orig[r][c]);
		}
	}

	printf("\nOriginal matrix (%d x %d): \n", matrix_sz, matrix_sz);
	print_matrix(matrix_orig, matrix_sz);

	printf("\nMapping matrix to 1D array.... \n");
	map_matrix_to_1d_array(matrix_orig, array_1d, matrix_sz);

	// printf("\n  1D array: \n"); // DEBUG
	// print_array(array_1d, matrix_sz*(matrix_sz+1)/2); // DEBUG

	printf("\nRebuilding matrix from 1D array... \n");
	rebuild_matrix_from_1d_array(array_1d, matrix_rebuilt, matrix_sz);

	printf("\nRebuilt matrix (%d x %d): \n", matrix_sz, matrix_sz);
	print_matrix(matrix_rebuilt, matrix_sz);


	return 0;
}

void map_matrix_to_1d_array(	const int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], 
									  int array_1d[MAX_MATRIX_SIZE],
								const int matrix_sz)
{
	int r, c, i = 0;

	// scan matrix and fill in array
	for(r = 0; r < matrix_sz; r++)
		for(c = 0; c < matrix_sz; c++)
			if(r >= c)
				array_1d[i++] = matrix[r][c];
}

void rebuild_matrix_from_1d_array(	const int array_1d[MAX_MATRIX_SIZE], 
										  int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],
									const int matrix_sz) 
{
	int r, c;
	for(r = 0; r < matrix_sz; r++)
		for(c = 0; c < matrix_sz; c++)
			matrix[r][c] = (r < c) ? 0 : array_1d[ r*(r+1) / 2 + c ];
}

// void print_array(	const int arr[MAX_MATRIX_SIZE], 
// 					const int len)
// {
// 	int i;
// 	for(i = 0; i < len; i++)
// 		printf("    [%2d]  %3d \n", i, arr[i]);
// 	printf("\n");
// }

void print_matrix(	const int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], 
					const int sz)
{
	int r, c;
	for(r = 0; r < sz; r++)
	{
		for(c = 0; c < sz; c++)
			printf("  %3d", matrix[r][c]);
		printf("\n");
	}
	printf("\n");
}