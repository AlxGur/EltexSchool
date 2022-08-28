#include "../lib/load_plug.h"



static void * Dlopen(char* filename, int flags)
{
	void * handle;
	printw("%s\n", filename);
	if((handle = dlopen(filename, flags)) == NULL)
	{
		printw("From dlopen: %s\n", dlerror());
		return NULL;
	}
	return handle;
}

static int Dlsym(void* handle, char* sym, void** buf)
{
	*buf = dlsym(handle, sym);
	char* err;
	if((err = dlerror()) != NULL)
	{
		printw("From dlsym: %s\n", err);
		return -1;
	}
	return 0;
}


//в случае успеха вернёт 0
//в случае ошибки - 1
//если в файле закончатся функции для считывания - -1
static int add_func(struct funcs* buf, size_t index_func_in_lib, void* handle)
{
	static void* h = NULL;

	static function* f_ptr = NULL;
	static int* count_ptr = NULL;

//Считываем колличество функций и массив структур, описывающих функции библиотеки
//если до этого они не был считан
	void* sym = NULL;
	if(h != handle)
	{
		if(Dlsym(handle, "count_func", &sym))
		{
			//В случае нправильного написания плагина (нет поля count_func)
			printw("Cant read lib (error in read count_func)\n");
			return 1;
		}
		count_ptr = (int*)sym;
		if(Dlsym(handle, "functions", &sym))
		{
			//В случае неравильного написания плагина (нет поля functions)
			printw("Cant read lib (error in read function)\n)");
			return 1;
		}
		f_ptr = (function*)sym;

		h = handle;
	}
	//Если индекс уже больше числа функций в библиотеке, надо закончить её читать
	if(*count_ptr <= index_func_in_lib)
	{
		h = NULL;
		f_ptr = NULL;
		count_ptr = NULL;
		return -1;
	}
	//Добавление указателя на функцию в буфер вместе с описывающёй её структурой
	size_t current = buf->cur;
	buf->f[current+1].f_param = f_ptr + index_func_in_lib;
	if(Dlsym(handle, buf->f[current+1].f_param->name_of_function, &sym))
	{
		//Если функция не была найдена
		printw("Cant read func: %s\n", buf->f[current+1].f_param->name_of_function);
		return 1;
	}
	buf->f[current+1].func_ptr = sym;
	buf->cur++;

	return 0;
}


void* load_plug(char* filename, struct funcs* buf)
{
	if(buf->f == NULL)
	{
		buf -> f = calloc(10, sizeof(struct func));
		buf->size = 10;
		buf->cur = -1;
	}

	void* handle = Dlopen(filename, RTLD_LAZY|RTLD_GLOBAL);
	if(handle == NULL)
	{
		printw("%s cant be open\n", filename);
		return NULL;
	}

	printw("handle : %p\n", handle);

	for(size_t i = 0;;i++)
	{
		if(buf->cur == buf->size - 1)
		{
			buf->f = realloc(buf->f, sizeof(struct func) * (buf->size + 10));
			buf->size += 10;
		}
		
		int status = add_func(buf, i, handle);

		if(status == -1)
			break;
		if(status == 1)
		{
			printf("Error in read plugin: %s\n", filename);
			break;
		}

		printw("Function %s loaded\n", buf->f[buf->cur].f_param->name_of_function);
	}
	return handle;
}