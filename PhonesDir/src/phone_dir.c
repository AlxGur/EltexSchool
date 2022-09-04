#include "../lib/phone_dir.h"

void print_entry(phone_entry* pe, FILE* file)
{
    if(stdout == file)
    {
        printw("-----(%ld)-----\n", pe->num);
        printw("Name: %s", pe->name);
        printw("Surname: %s", pe->surname);
        printw("Phone number: %s", pe->phone_number);
        return;
    }
    fprintf(file, "-----(%ld)-----\n", pe->num);
    fprintf(file, "Name: %s", pe->name);
    fprintf(file, "Surname: %s", pe->surname);
    fprintf(file, "Phone number: %s", pe->phone_number);
}

void free_phone_dir(phones* p)
{
    if(NULL == p)
    {
        return;
    }
    for(int i = 0; i <= p->cur; i++)
    {
        free(p->pe[i].name);
        free(p->pe[i].surname);
        free(p->pe[i].phone_number);
    }
    free(p);
}