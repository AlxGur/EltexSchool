#include "../lib/print_reverse_arr.h"
#include "../lib/stepped_matrix.h"
#include "../lib/fill_matrix_snail.h"
#include <ncurses.h>

static inline void print_menu()
{
    printw("1) Print reverse arr\n\
2) Print stepped matrix\n\
3) Print snail matrix\n\
4) Exit\n");
}

int main()
{
    initscr();
    noecho();
    cbreak();
    refresh();
    move(0, 0);
    int exit = 0;
    while (0 == exit)
    {
        printw("Press any key to continue\n");
        noecho();
        refresh();
        getch();
        move(0, 0);
        clear();
        refresh();
        print_menu();
        char c = getch();
        printw("%c\n", c);
        refresh();
        echo();
        switch(c)
        {
            case '1':
                print_reverse_arr();
                break;
            case '2':
                stepped_matrix();
                break;
            case '3':
                fill_snail_matrix();
                break;
            case '4':
                exit = 1;
                break;
            default:
                break;
        }
    }
    endwin();
}