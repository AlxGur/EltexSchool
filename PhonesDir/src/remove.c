#include "../lib/remove.h"

void remove_entry(phones* p)
{
    if(p->cur == -1)
    {
        printw("Phones is empty\n");
        return;
    }
    size_t num_of_del;
    printw("Print num of entry:\n");
    scanw("%ld", &num_of_del);
    if(num_of_del > p->cur+1 || num_of_del <= 0)
    {
        printw("Entry with %ld number cant be deleted(no exist)\n", num_of_del);
        return;
    }

    int entry_was_deleted = 0;
    for(int i = 0; i <= p->cur; i++)
    {
        if(entry_was_deleted)
        {
            p->pe[i-1].name = p->pe[i].name;
            p->pe[i-1].surname = p->pe[i].surname;
            p->pe[i-1].phone_number = p->pe[i].phone_number;
        }
        if(num_of_del == p->pe[i].num)
        {
            free(p->pe[i].name);
            free(p->pe[i].surname);
            free(p->pe[i].phone_number);
            entry_was_deleted = 1;
        }
    }
    p->cur--;
}