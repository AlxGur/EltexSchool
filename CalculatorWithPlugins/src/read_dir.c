#include "../lib/read_dir.h"

int my_cmp(const struct dirent *de)
{
	if (strcmp(de->d_name, ".") && strcmp(de->d_name, ".."))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct dirent** read_dir(char* dir, size_t* size)
{
	struct dirent** direntry;
	if (*size = scandir(dir, &direntry, my_cmp, alphasort))
	{
		direntry[*size] = NULL;
		return direntry;
	}	
	else
	{
		perror("");
		return 0;
	}

}