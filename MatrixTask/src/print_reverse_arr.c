#include "../lib/print_reverse_arr.h"

void print_reverse_arr()
{
	long int N;
	
	printw("Print size array: ");
	if (scanw("%ld", &N) <= 0)
	{
		printw("uncorrect value\n");
		return;
	}

	int * arr = (int *) malloc(sizeof(int) * N);

	for(int i = 0; i < N; i++)
	{
		if (scanw("%d", arr + i) <= 0)
		{
			printw("uncorrect value\n");
			return;
		}
	}

	for(int i = 0; i < N / 2; i++)
	{
		arr[N - 1 - i] += arr[i];
		arr[i] = arr[N - 1 - i] - arr[i];
		arr[N - 1 - i] -= arr[i];
	}	

	for(int i = 0; i < N; i++)
	{
		printw("%d ", arr[i]);
	}
	printw("\n");


	free(arr);
}