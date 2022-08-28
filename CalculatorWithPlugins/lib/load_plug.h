#ifndef LOAD_PLUG
#define LOAD_PLUG

#include <dlfcn.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>
#include <ncurses.h>
#include "struct_for_plug.h"

struct func
{
	void *func_ptr;
	function* f_param;
};

struct funcs
{
	struct func* f;
	size_t cur;
	size_t size;
};

//По имени плагина заполняет структуру func в структуру funcs
void* load_plug(char* filename, struct funcs* buf);

#endif