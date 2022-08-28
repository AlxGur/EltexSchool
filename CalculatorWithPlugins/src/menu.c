#include "../lib/struct_for_plug.h"
#include "../lib/load_plug.h"
#include "../lib/load_plugins.h"
#include <stdio.h>
#include <ncurses.h>

int scan_command(int count_of_commands)
{
	while(1)
	{
		printw("Print command (0 is exit):\n");
		int comm;
		if (scanw("%d", &comm) <= 0)
		{
			printw("Print correct command");
			continue;	
		}
		if(comm < count_of_commands + 1 && comm >= 0)
			return comm;
		printw("Print correct command");
	}
}

void print_menu(struct funcs * buf)
{
	printw("MENU:\n");
	for(int i = 0; i <= buf->cur; i++)
	{
		printw("%d) %s\n", i+1, buf->f[i].f_param->name_of_function);
	}
}

void execute_command(int num_command, struct funcs* buf, ...)
{
	int index = num_command - 1;
	if(buf->cur < index || buf->cur < 0)
		return;
	void(*a)(char*, ...);
	a = buf->f[index].func_ptr;
	a(buf->f[index].f_param->args_format);
}

int main()
{
	initscr();
	move(0, 0);
	struct funcs buf = {NULL, -1, 0};
	char* path = malloc(256);
	int size = 256;
	while(1)
	{
		if(getcwd(path, 256 - sizeof("plugins/")))
			break;
		size +=50;
		path = realloc(path, size);
	}
	strcat(path, "/plugins/");	
	printw("path = %s\n", path);


	size_t size_links = 0;
	void ** links = load_plugins(path, &buf, &size_links);
	if(NULL == links)
	{
		printw("error files not found");
	}
	getch();
	free(path);

	while(1)
	{
		clear();
		move(0, 0);
		refresh();
		print_menu(&buf);
		int comm;
		if(!(comm = scan_command(buf.cur+1)))
			break;
		execute_command(comm, &buf);
		printw("Press any key to continue\n");
		getch();
	}

	for(int i = 0; i < size_links; i++)
	{
		dlclose(links[i]);
	}
	free(links);
	
	endwin();
}