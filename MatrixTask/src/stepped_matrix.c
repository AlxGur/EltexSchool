#include "../lib/stepped_matrix.h"

void stepped_matrix()
{
	long int N;
	printw("Print size of matrix: ");
	int ret = scanw("%ld", &N);
	if(ret <= 0)
	{
		printw("uncorrect value\n");
		return;
	}

	int ** matrix = (int **) malloc(sizeof(int*) * N);

	for(int i = 0; i < N; i++)
			matrix[i] = (int *) malloc(sizeof(int) * N);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i + j + 1 <= N)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printw("%d ", matrix[i][j]);
		}
		printw("\n");
	}

	for(int i = 0; i < N; i++)
			free (matrix[i]);
	free (matrix);
}