#include "../lib/process_tree.h"
#include "../lib/simple_create_process.h"

int main()
{
    int st = 0;
    while(st != 3)
    {
        printf("1) Simple create process\n");
        printf("2) Process tree\n");
        printf("Another key for exit\n");
        scanf("%d", &st);
        switch (st)
        {
        case 1:
            simple_create_process();
            break;
        case 2:
            process_tree();
            break;
        default:
            st = 3;
            break;
        }
    }
    return 0;
}