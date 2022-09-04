#include "../lib/mymatrix.h"

void init_matrix(long int row, long int col, long int*** buf)
{
	*buf = (long int **)malloc(row * sizeof(long int*));

	for(int i = 0; i < row; i++)
	{
		(*buf)[i] = (long int*) malloc(col * sizeof(long int));
	}
}

void init_and_scan_matrix(long int * bufrow, long int * bufcol, long int*** bufmatrix, int is_square_matrix)
{
	printw("Print size of matrix: \n");
	printw("Str: ");
	if (scanw("%ld", bufrow) <= 0)
	{
		printw("uncorrect value\n");
		return;
	}
	if (is_square_matrix)
	{
		*bufcol = *bufrow;
	}
	else
	{
		printw("Col: ");
		if (scanw("%ld", bufcol) <= 0)
		{
			printw("uncorrect value\n");
			return;
		}
	}
	init_matrix(*bufrow, *bufcol, bufmatrix);

	printw("Print your matrix: \n");

	for(int i = 0; i < *bufrow; i++)
	{
		for(int j = 0; j < *bufcol; j++)
		{
			if (scanw("%ld", &((*bufmatrix)[i][j])) <= 0)
			{
				printw("uncorrect value\n");
				return;
			}
		}
	}
}

void print_matrix(long int row, long int col, long int ** matrix)
{
	for(int i = 0; i < row; i++)
	{
		for(int  j = 0; j < col; j++)
		{
			printw("%ld ", matrix[i][j]);
		}
		printw("\n");
	}
}

void delete_matrix(long int row, long int ** matrix)
{
	for(long int i = 0; i < row; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}
