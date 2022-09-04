#include "../lib/write_read_file.h"

static inline int Open(char* pathname)
{
	int fd;
	int ret = fd = open(pathname, O_RDWR|O_CREAT, S_IRUSR | S_IWUSR);
	if(ret < 0)
	{
		printf("%d", fd);
		perror("Cant open file: ");
		exit (-1);
	}	
	return fd;
}

void write_read_file(char* path, char* msg, int msg_size)
{
	int fd = Open(path);
	write(fd, msg, msg_size);
	syncfs(fd);
	lseek(fd, 0, SEEK_SET);
	char* strBuf = malloc(msg_size);
	read(fd, strBuf, msg_size);
	printf("%s\n", strBuf);
	close(fd);
	free(strBuf);
}