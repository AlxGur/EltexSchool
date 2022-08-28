//В секции глобальных переменных для каждой динамической библиотеки должен существовать массив function functions[]
//Необходимо для каждой функции создать структуру function
//functions - массив таких структур
//Также должна существовать глобальная переменная count_func, хранящая колличество функций в плагине
//Каждая экспортируемая функция должна иметь вид some_func_name() (count_args - количество аргументов)

#ifndef STRUCT_FOR_PLUG
#define STRUCT_FOR_PLUG

enum ret_t
{
	v, i, d, c, s, d_p, i_p
};

typedef struct struct_for_func
{
	char* name_of_function;

	//args_format:
	//NULL - no arg
	//i- int 
	//d - double
	//c - char
	//s - char* 
	//d* - double*
	//i* - int *
	char* args_format;

	enum ret_t return_type;

} function;

#endif