#ifndef READ_FILE_FROM_END_H
#define READ_FILE_FROM_END_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void read_file_from_end(char* path);

#endif