#include "../lib/print_all.h"

void print_all_entries(phones* p, FILE* file)
{
    if(p->cur == -1)
    {
        printw("Phones is empty\n");
        return;
    }

    for(size_t i = 0; i <= p->cur; i++)
        print_entry((p->pe) + i, file);
}