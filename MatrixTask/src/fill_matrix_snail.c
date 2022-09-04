#include "../lib/fill_matrix_snail.h"

enum directions {RIGHT, DOWN, LEFT, UP};

static inline long int ** init_square_long_int_matrix(long int size)
{
	long int ** matrix = (long int**)malloc(sizeof(long int*) * size);

	for(long int i = 0; i < size; i++)
	{
		matrix[i] = (long int *)malloc(sizeof(long int) * size);
	}

	return matrix;
}

static inline void fill_subline(long int size, enum directions direction, long int ** matrix, long int start_i, long int start_j, int * count)
{

	switch (direction)
	{
		case (RIGHT):
				for(int j = 0; j < size; j++)
				{
					matrix[start_i][start_j + j] = (*count);
					(*count)++;
				}
			break;

		case (DOWN):
				for(int i = 1; i < size; i++)
					{
						matrix[start_i + i][start_j] = (*count);
						(*count)++;
					}
			break;

		case (LEFT):
				for(int j = 1; j < size; j++)
					{
						matrix[start_i][start_j - j] = (*count);
						(*count)++;
					}
			break;

		case (UP):
				for(int i = 1; i < size - 1; i++)
					{
						matrix[start_i - i][start_j] = (*count);
						(*count)++;
					}
			break;
	}
}


static inline void fill_spiral(long int size_spiral, long int ** matrix)
{
	long int i = 0;
	long int j = 0;
	int count = 1;
	while(size_spiral > 1)
	{
		fill_subline(size_spiral, RIGHT, matrix, i, j, &count);
		j +=size_spiral - 1;

		fill_subline(size_spiral, DOWN, matrix, i, j, &count);
		i += size_spiral - 1;

		fill_subline(size_spiral, LEFT, matrix, i, j, &count);
		j -=size_spiral - 1;

		fill_subline(size_spiral, UP, matrix, i, j, &count);
		i -= size_spiral - 2;

		j += 1;

		size_spiral = size_spiral - 2;
	}

	if(size_spiral == 1)
		fill_subline(size_spiral, RIGHT, matrix, i, j, &count);
}

void fill_snail_matrix()
{
	long int N;
	
	printw("Print size of matrix ");
	int ret = scanw("%ld", &N);
	if(ret <= 0)
	{
		printw("uncorrect value\n");
		return;
	}

	long int** matrix = init_square_long_int_matrix(N);
	fill_spiral(N, matrix);
	print_matrix(N, N, matrix);
	
	delete_matrix(N, matrix);
}