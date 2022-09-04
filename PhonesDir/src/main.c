#include "../lib/add.h"
#include "../lib/find_entry.h"
#include "../lib/print_all.h"
#include "../lib/remove.h"
#include "../lib/read_file.h"
#include "../lib/write_file.h"

static inline void print_menu()
{
    printw("1) Add entry\n2) Remove entry\n3) Find\n4) Show all entries\n5) Exit\n");
}

static inline int scan_command()
{
    int c;
    while(1)
    {
        c = getch();
        printw("\n");
        c = c - '1' + 1;
        if(c <= 0 || c > 5)
        {
            printw("Enter correct command\n");
        }
        else
        {
            break;
        }
    }
    return c;
}

int main()
{
    initscr();
    cbreak();
    echo();

    phones* ph = NULL;
    read_file(&ph);

    int was_exit = 0;
    while(!was_exit)
    {
        clear();
        printw("Menu\n");
        print_menu();
        echo();

        int command = scan_command();
        switch (command)
        {
        case 1:
            add(ph);
            break;
        case 2:
            remove_entry(ph);
            break;
        case 3:
            find(ph);
            break;
        case 4:
            print_all_entries(ph, stdout);
            break;
        case 5:
            was_exit = 1;
            break;
        default:
            break;
        }
        printw("Press any key\n");
        getch();
    }

    write_file(ph);

    FILE* file = fopen("Phone_dir.txt", "w");
    print_all_entries(ph, file);
    fclose(file);

    free_phone_dir(ph);
    ph = NULL;

    endwin();
    return 0;
}