#include <stdio.h>
#include <ncurses.h>
#include "../lib/struct_for_plug.h"

int count_func = 1;

function functions[] = 
{
	{"div", NULL, v}
};

void div(char* fmt, ...)
{
	int a, b;
	printw("Print args for div: \n");
	scanw("%d %d", &a, &b);
	printw("Result: %f\n", (double)a/b);
}
