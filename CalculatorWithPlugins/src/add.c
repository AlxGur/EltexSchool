#include <stdio.h>
#include <ncurses.h>
#include "../lib/struct_for_plug.h"

int count_func = 1;

function functions[] = 
{
	{"add", NULL, v}
};

void add(char* fmt, ...)
{
	int a, b;
	printw("Print args for sum: \n");
	scanw("%d %d", &a, &b);
	printw("Result: %d\n", a+b);
}
