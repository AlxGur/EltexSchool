#include <stdio.h>
#include <ncurses.h>
#include "../lib/struct_for_plug.h"

int count_func = 1;

function functions[] = 
{
	{"sub", NULL, v}
};

void sub(char* fmt, ...)
{
	int a, b;
	printw("Print args for sub: \n");
	scanw("%d %d", &a, &b);
	printw("Result: %d\n", a-b);
}
