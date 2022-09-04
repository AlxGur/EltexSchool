#ifndef MY_MATRIX
#define MY_MATRIX

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void init_matrix(long int str, long int col, long int*** buf);

void init_and_scan_matrix(long int * bufstr, long int * bufcol, long int*** bufmatrix, int is_square_matrix);

void delete_matrix(long int str, long int ** matrix);

void print_matrix(long int str, long int col, long int ** matrix);

#endif