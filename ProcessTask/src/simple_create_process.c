#include "../lib/simple_create_process.h"

void simple_create_process()
{
	int pid = fork();
	if(pid < 0)
	{
		perror("");
		exit(-1);
	}
	if(!pid)
	{
		printf("from 2nd process: pid:%d\n", getpid());
		exit(0);
	}
	printf("from 1st process: pid:%d\n", getpid());
	waitpid(pid, NULL, 0);
}