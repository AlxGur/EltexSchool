#ifndef WRITE_READ_FILE_H
#define WRITE_READ_FILE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <malloc.h>


void write_read_file(char* path, char* msg, int msg_size);

#endif