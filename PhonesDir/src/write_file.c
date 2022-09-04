#include "../lib/write_file.h"

void write_file(phones * p)
{
    FILE* file = fopen("Phone_dir", "w");

    for(int i = 0; i <= p->cur; i++)
    {
        fwrite((size_t*)&(p->pe[i]), sizeof(size_t), 4, file);
        fwrite(p->pe[i].name, sizeof(int), p->pe[i].name_size, file);

        fwrite(p->pe[i].surname, sizeof(int), p->pe[i].surname_size, file);

        fwrite(p->pe[i].phone_number, sizeof(int), p->pe[i].phone_number_size, file);
    }

    fclose(file);
}