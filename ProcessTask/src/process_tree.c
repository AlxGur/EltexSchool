#include "../lib/process_tree.h"


int Fork()
{
	int pid = fork();
	if(pid < 0)
	{
		perror("in fork:");
		exit(-1);
	}
	return pid;
}

int create_sleep_process(int num)
{
	int pid = Fork();

	if(!pid)
		{
			printf("From %d process: pid: %d  ppid:  %d\n", num, getpid(), getppid());
			exit(0);
		}
	return pid;
}

void process_tree()
{
	int pid1 = Fork();

	if(!pid1)
	{	
		printf("From 2nd process: pid: %d  ppid:  %d\n", getpid(), getppid());
		int pid1 = create_sleep_process(4);
		int pid2 = create_sleep_process(5);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		exit(0);
	}
	printf("From 1st process: pid: %d  ppid: %d\n", getpid(), getppid());
	int pid2 = Fork();
	if(!pid2)
	{
		printf("From 3rd process: pid: %d  ppid:  %d\n", getpid(), getppid());
		int pid = create_sleep_process(6);
		waitpid(pid, NULL, 0);
		exit(0);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}