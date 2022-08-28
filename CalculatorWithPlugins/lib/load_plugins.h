#ifndef LOAD_PLUGINS_H
#define LOAD_PLUGINS_H

#include <unistd.h>
#include <string.h>
#include "load_plug.h"
#include "read_dir.h"

//считывает директорию и заполняет структуру buf
void ** load_plugins(char* dirname, struct funcs* buf, size_t* size_links_buf);

#endif