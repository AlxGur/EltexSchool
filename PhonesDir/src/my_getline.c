#include "../lib/my_getline.h"


 int my_getline(char** buf, size_t* size)
{
    if(NULL== size)
    {
        return -1;
    }
    if(NULL == *buf)
    {
        (*size) = 10;
        (*buf) = calloc(*size, sizeof(int));
    }
    int c;
    int index = 0; 
    while(1)
    {
        noecho();
        c = getch();
        printw("%c", c);
        if(index == (*size) - 1)
        {
            (*size) += 10;
            (*buf) = realloc((*buf), sizeof(int) * (*size));
            getch();
        }

        (*buf)[index] = c;

        index++;

        if('\n' == c)
        {
            break;
        }
    }
    printw("\n");
    (*buf)[index] = '\0';
    echo();
    return index;
}