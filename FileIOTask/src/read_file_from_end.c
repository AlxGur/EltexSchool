#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static inline int Open(char* pathname)
{
	int fd;

	if((fd = open(pathname, O_RDONLY)) < 0)
	{
		printf("%d", fd);
		perror("Error: ");
		return -1;
	}
	return fd;
}

static inline long int Lseek(int fd, int off, int pos)
{
	long int l;
	if((l = lseek(fd, off, pos)) < 0)
	{
		errno = 0;
		return -1;
	}
	return l;
}

void read_file_from_end(char* path)
{
	int fd = Open(path);
	Lseek(fd, -1, SEEK_END);
	char a;
	do
	{		
		read(fd, &a, 1);
		printf("%c", a);
	} while(Lseek(fd, -2, SEEK_CUR) != -1);
	close(fd);
}