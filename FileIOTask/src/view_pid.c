#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void view_pid()
{
	printf("Your pid:\n");
	printf("%d\n", getpid());
}