#include <stdio.h>
#include <ncurses.h>
#include "../lib/struct_for_plug.h"

int count_func = 1;

function functions[] = 
{
	{"mul", NULL, v}
};

void mul(char* fmt, ...)
{
	int a, b;
	printw("Print args for mul: \n");
	scanw("%d %d", &a, &b);
	printw("Result: %d\n", a*b);
}
