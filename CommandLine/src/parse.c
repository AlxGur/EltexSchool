#include <malloc.h>
#include <string.h>
#include "../lib/parse.h"


#define BUF_START_SIZE 10


char* get_command()
{
	char* str = NULL;
	size_t buf_size = 0;
	getline(&str, &buf_size, stdin);
	return str;
}

char** get_args(char* str, char* sep)
{
	size_t buf_size = BUF_START_SIZE;
	char** buf_tokens = (char **) malloc(sizeof(char*) * buf_size);
	buf_tokens[0] = strtok(str, sep);
	
	if(!buf_tokens[0])
	{
		buf_tokens[1] = NULL;
		return buf_tokens;
	}

	for(int i = 1;; i++)
	{
		buf_tokens[i] = strtok(NULL, sep);
		if(i == buf_size - 1)
		{
			buf_size += BUF_START_SIZE;
			char** old_ptr = buf_tokens;
			buf_tokens = (char**)realloc(buf_tokens, sizeof(char*) * buf_size);
			free(old_ptr);
		}

		if(!buf_tokens[i])
			return buf_tokens;
	}
}