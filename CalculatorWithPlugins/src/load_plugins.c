#include "../lib/load_plugins.h"

void ** load_plugins(char* dirname, struct funcs* buf, size_t * size_link_buf)
{
	if(buf->f != NULL)
	{
		printw("buf need be empty for load plagins\n");
		getch();
		exit(-1);
	}
	struct dirent** nms;
	size_t size;
	if (!(nms = read_dir(dirname, &size)))
	{
		printw("error\n");
		getch();
		return NULL;	
	}

	struct dirent** buf_d = nms;
	*size_link_buf = 0;
	void ** buf_links = malloc((size + 1) * sizeof(void*));
	buf_links[size] = NULL;
	char* path;
	while(*buf_d)
	{
		printw("%s\n", (*buf_d)->d_name);
		path = malloc(256);
		path[0] = '\0';
		strcat(path, dirname);
		strcat(path, (*buf_d)->d_name);
		buf_links[*size_link_buf] = load_plug(path, buf);
		if(buf_links[*size_link_buf])
			(*size_link_buf)++;
		free(*buf_d);
		free(path);
		buf_d++;
	}

	free(nms);
	return buf_links;
}
