#ifndef READ_DIR_H
#define READ_DIR_H

#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

struct dirent** read_dir(char* dir, size_t * size);

#endif