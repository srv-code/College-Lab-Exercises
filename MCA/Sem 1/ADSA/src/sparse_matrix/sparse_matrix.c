#include <stdio.h>

typedef struct 
{
	int	row_idx,
		col_idx,
		nz_val;
} sparse_matrix_rep;

void print_matrix(const int matrix[4][3], const int row_size, const int col_size)
{
	int r, c;
	for(r = 0; r < row_size; r++)
	{
		for(c = 0; c < col_size; c++)
			printf("%3d  ", matrix[r][c]);
		printf("\n");
	}
}

void store_matrix_to_1D_array(const int matrix[4][3], const int row_size, const int col_size, sparse_matrix_rep* info)
{
	int nz_val_count = 0, matrix_row, matrix_col, info_idx = 0;
	info[0].row_idx = row_size;
	info[0].col_idx = col_size;
	
	// scan the entire 2D matrix and fill into info as reqd
	for(matrix_row = 0; matrix_row < row_size; matrix_row++)
	{
		for(matrix_col = 0; matrix_col < col_size; matrix_col++)
		{
			if(matrix[matrix_row][matrix_col] != 0)
			{
				nz_val_count++;
				info_idx++;
				info[info_idx].row_idx = matrix_row;
				info[info_idx].col_idx = matrix_col;
				info[info_idx].nz_val  = matrix[matrix_row][matrix_col];				
			}
		}
	}
	
	info[0].nz_val = nz_val_count;
}

void rebuild_matrix_from_1D_array(const sparse_matrix_rep* info, int matrix[4][3])
{
	int	info_idx = 1, 
		info_len = info[0].nz_val,
		matrix_col_size = info[0].col_idx, 
		matrix_row_size = info[0].row_idx, 
		matrix_row_idx, matrix_col_idx;

	for(matrix_row_idx = 0; matrix_row_idx < matrix_row_size; matrix_row_idx++)
		for(matrix_col_idx = 0; matrix_col_idx < matrix_col_size; matrix_col_idx++)
			if(info_idx <= info_len && info[info_idx].row_idx == matrix_row_idx && info[info_idx].col_idx == matrix_col_idx)
			{
				// printf("  [Filling from info[%d][%d]] \n", matrix_row_idx, matrix_col_idx);
				matrix[matrix_row_idx][matrix_col_idx] = info[info_idx].nz_val;
				info_idx++;
			}
			else 
				matrix[matrix_row_idx][matrix_col_idx] = 0;
}

// void print_sparse_matrix_info(const sparse_matrix_rep* info)
// {
// 	int i, len;	
// 	for(i = 0, len = info[0].nz_val; i <= len; i++)
// 		printf("  info[%d]: row_idx=%3d, col_idx=%3d, nz_val=%3d \n", i, info[i].row_idx, info[i].col_idx, info[i].nz_val);
// 	printf("\n");
// }

int main() 
{
	const int ROW_SIZE = 4, COL_SIZE = 3;
	sparse_matrix_rep sparse_matrix_info[20];
	int matrix_org[ROW_SIZE][COL_SIZE], matrix_rebuilt[ROW_SIZE][COL_SIZE], r, c;
	
	system("clear");
	
	printf("Enter values in matrix: \n");
	for(r = 0; r < ROW_SIZE; r++)
	{
		printf("  Enter for row %d: \n", r);
		for(c = 0; c < COL_SIZE; c++)
		{
			printf("    Enter for column %d:  ", c);			
			scanf("%d", &matrix_org[r][c]);
		}
	}
	
	printf("\nOriginal matrix (%d x %d): \n", ROW_SIZE, COL_SIZE);	
	print_matrix(matrix_org, ROW_SIZE, COL_SIZE);
	
	printf("\nStoring matrix in 1D array... \n");
	store_matrix_to_1D_array(matrix_org, ROW_SIZE, COL_SIZE, sparse_matrix_info);

	// printf("\nInfo: \n"); // DEBUG
	// print_sparse_matrix_info(sparse_matrix_info); // DEBUG
	
	printf("\nRe-building matrix from 1D array...\n");	
	rebuild_matrix_from_1D_array(sparse_matrix_info, matrix_rebuilt);
	
	printf("\nRebuilt matrix (%d x %d): \n", ROW_SIZE, COL_SIZE);	
	print_matrix(matrix_rebuilt, ROW_SIZE, COL_SIZE);
	
	
	return 0;
}