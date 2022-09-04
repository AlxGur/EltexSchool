#include "../lib/view_pid.h"
#include "../lib/write_read_file.h"
#include "../lib/read_file_from_end.h"
#define EXIT_NUM 10

static inline void print_menu()
{
    printf("1) View pid\n2) Open file and write to it\n3) Read file from end\n");
}

int main()
{
    int st = 0;
    while(st != EXIT_NUM)
    {
        print_menu();
        scanf("%d", &st);
        switch (st)
        {
        case 1:
            view_pid();
            break;
        case 2:
            char str[] = "Hello\n world\n";
            write_read_file("some_name", str, sizeof("Hello\n world\n"));
            break;
        case 3:
            read_file_from_end("some_name");
            break;
        default:
            st = EXIT_NUM;
            break;
        }
    }
    return 0;
}