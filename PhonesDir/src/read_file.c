#include "../lib/read_file.h"

void read_file(phones ** p)
{
    FILE* file = fopen("Phone_dir", "a+");
    if(file == NULL)
        return;
    
    if(*p == NULL)
    {
        (*p) = malloc(sizeof(phones));
        (*p)->cur = -1;
        (*p)->size = 10;
        (*p)->pe = malloc((*p)->size * sizeof(phone_entry));
    }


    while(fread(&((*p)->pe[(*p)->cur+1]), sizeof(size_t), 4, file))
    {
        if((*p)->cur >= (*p)->size - 1)
        {
            (*p)->pe = realloc((*p)->pe, sizeof(phone_entry) * ((*p)->size + 10));
            (*p)->size += 10;
        }
        (*p)->pe[(*p)->cur+1].name = malloc(sizeof(int) * (*p)->pe[(*p)->cur+1].name_size);
        fread((*p)->pe[(*p)->cur+1].name, sizeof(int), (*p)->pe[(*p)->cur+1].name_size, file);

        (*p)->pe[(*p)->cur+1].surname = malloc(sizeof(int) * (*p)->pe[(*p)->cur+1].surname_size);
        fread((*p)->pe[(*p)->cur+1].surname, sizeof(int), (*p)->pe[(*p)->cur+1].surname_size, file);

        (*p)->pe[(*p)->cur+1].phone_number = malloc(sizeof(int) * (*p)->pe[(*p)->cur+1].phone_number_size);
        fread((*p)->pe[(*p)->cur+1].phone_number, sizeof(int), (*p)->pe[(*p)->cur+1].phone_number_size, file);

        (*p)->cur++;
    }
    fclose(file);
}