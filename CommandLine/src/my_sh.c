#include "../lib/parse.h"
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


#define SEP " \n\t"
#define PIPE_SEP "|"
#define MK_PIPE 0b1
#define FIRST_COMMAND 0b10
#define LAST_COMMAND 0b100

void Free(char* command, char** commands, char** args)
{
	if(command)
		free(command);
	if(commands)
		free(commands);
	if(args)
		free(args);
}

int execute_programm(char* command, char** args, int options)
{
	if(!args[0])
	{
		return 1;
	}

	static int fd_stdin = -1;
	static int fd_stdout = -1;

	if(!strcmp(command, "exit") || !strcmp(args[0], "exit"))
	{
		if(fd_stdout != -1)
			close(fd_stdin);
		if(fd_stdin != -1)
			close(fd_stdout);
		return 0;
	}

	static int fd[2] = {-1, -1};
	
	if(options & MK_PIPE)
	{
		if(options & FIRST_COMMAND)
		{
			fd_stdin = dup(0);
			fd_stdout = dup(1);
		}

		if(options & FIRST_COMMAND)
		{
			pipe(fd);
			//Заменить 1 дескриптор
			close(1);
			dup2(fd[1], 1);
			close(fd[1]);
			fd[1] = -1;
		} else
			{
				//Заменить 0 дескриптор
				close(0);
				dup2(fd[0], 0);
				close(fd[0]);
				fd[0] = -1;

				if(!(options & LAST_COMMAND))
				{
					pipe(fd);
					//Заменить 1 дескриптор
					close(1);
					dup2(fd[1], 1);
					close(fd[1]);
					fd[1] = -1;
				} else
				{
					//Заменить 1 дескриптор на изначальный
					close(1);
					dup2(fd_stdout, 1);
				}
		}
	}

	pid_t pid;

	if((pid = fork()) < 0)
	{
		close(fd[0]);
		close(fd[1]);
		fd[0] = -1;
		fd[1] = -1;
		dup2(fd_stdin, 0);
		dup2(fd_stdout, 1);
		perror("my_sh");
		return -1;
	}

	if(!pid)
	{
		
		execvp(args[0], args);

		perror("my_sh");
		exit(-1);
	}
	if(options & LAST_COMMAND)
			dup2(fd_stdin, 0);
	int wstat;
	waitpid(pid, &wstat, 0);
	return 1;
}



int main()
{
	int was_exited = 0;

	while(!was_exited)
	{
		printf(">");

		//Command whith |
		char* command = get_command();
		//Commands without |
		char** commands = get_args(command, PIPE_SEP);
		char** args = NULL;
		for(int i = 0; commands[i]; i++)
		{
			char** args = get_args(commands[i], SEP);

			int options = (0 == i && NULL == commands[i+1]) ? 0 : MK_PIPE;
			if(options)
			{
				options |= commands[i + 1] ? 0 : LAST_COMMAND;
				options |= i == 0 ? FIRST_COMMAND : 0;
			}
			
			if(!execute_programm(command, args, options))
			{
				free(args);
				was_exited = 1;
				break;
			}
		}
		Free(command, commands, args);
		command = NULL;
		commands = NULL;
		args = NULL;
	}
	return 0;
}