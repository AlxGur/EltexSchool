#ifndef PHONE_DIR_H
#define PHONE_DIR_H

#include <stdio.h>
#include <ncurses.h>
#include <malloc.h>

typedef struct phone_entry
{
    size_t num;
    size_t name_size;
    size_t surname_size;
    size_t phone_number_size;
    char* name;
    char* surname;
    char* phone_number;
} phone_entry;

typedef struct
{
    int size;
    int cur;
    phone_entry* pe;
} phones;

void print_entry(phone_entry* pe, FILE* file);
void free_phone_dir(phones* p);

#endif