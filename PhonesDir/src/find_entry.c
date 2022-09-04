#include "../lib/find_entry.h"

static void inline find_from_all(phones* p)
{
    printw("Print string for find it: \n");
    size_t size_buf = 0;
    size_t size;
    char* str_for_find = NULL;
    size = my_getline(&str_for_find, &size_buf);
    for(size_t i = 0; i <= p->cur; i++)
    {
        if((!strncmp(p->pe[i].phone_number, str_for_find, size - 1)) ||
            (!strncmp(p->pe[i].name, str_for_find, size - 1)) ||
            (!strncmp(p->pe[i].surname, str_for_find, size - 1)))
            print_entry(p->pe + i, stdout);
    }
}

static void inline find_from_field(phones* p)
{
    char st = 0;
    while(1)
    {
        printw("Print num of field for find: \n1) Name\n2) Surname\n3) Phone number\n");
        st = getch();
        printw("\n");
        if(st < '1' || st > '3')
            printw("Print correct num(1-3)\n");
        else
            break;
    }
    printw("Print string for find it: \n");
    size_t size_buf = 0;
    char* str_for_find = NULL;
    size_t size = my_getline(&str_for_find, &size_buf);
    for(size_t i = 0; i <= p->cur; i++)
    {
        switch (st)
        {
        case '1':
            if(!strncmp(p->pe[i].name, str_for_find, size-1))
                print_entry(p->pe + i, stdout);
            break;
        case '2':
            if(!strncmp(p->pe[i].surname, str_for_find, size-1))
                print_entry(p->pe + i, stdout);
            break;
        case '3':
            if(!strncmp(p->pe[i].phone_number, str_for_find, size-1))
                print_entry(p->pe + i, stdout);
            break;
        default:
            break;
        }
    }
}

void find(phones* p)
{
    if(p->cur == -1)
    {
        printw("Phones is empty\n");
        return;
    }
    char st = 0;
    while(1)
    {
        printw("Print num of mode find:\n1) Find from all entries\n2) Find from field\n");
        st = getch();
        printw("\n");
        if(st == '1' || st == '2')
        {
            break;
        }
        else
            printw("Print 1 or 2\n");
    }
    switch (st)
    {
        case '1':
            find_from_all(p);
            break;
        case '2':
            find_from_field(p);
            break;
        default:
            break;
    }
}