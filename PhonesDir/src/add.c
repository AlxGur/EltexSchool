#include "../lib/add.h"


void add(phones* p)
{
    if(p -> cur == p -> size - 1)
    {
        phone_entry* buf = p->pe;
        p -> pe = realloc(p -> pe, sizeof(phone_entry) * (p -> size + 10));
        p->size += 10;
        free(buf);
    }
    size_t size = 0;
    p->pe[p->cur+1].name = NULL;
    p->pe[p->cur+1].surname = NULL;
    p->pe[p->cur+1].phone_number = NULL;

    printw("Print name:\n");
    refresh();
    p->pe[p->cur+1].name_size = my_getline(&p->pe[p -> cur + 1].name, &size);

    printw("Print surname:\n");
    refresh();
    p->pe[p->cur+1].surname_size = my_getline(&p->pe[p -> cur + 1].surname, &size);

    printw("Print phone number:\n");
    refresh();
    p->pe[p->cur+1].phone_number_size = my_getline(&p->pe[p -> cur + 1 ].phone_number, &size);

    if(p->cur != -1)
        p->pe[p -> cur + 1].num = p->pe[p -> cur].num + 1;
    else
        p->pe[p -> cur + 1].num = 1;
    p->cur++;
}