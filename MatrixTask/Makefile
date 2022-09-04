SRC = main.c fill_matrix_snail.c print_reverse_arr.c \
		stepped_matrix.c mymatrix.c

FLAGS = 

OBJ = main.o fill_matrix_snail.o print_reverse_arr.o stepped_matrix.o mymatrix.o

LIB = -lncurses

BIN = matrixTask

LIBPATH = ./lib

SRCPATH = ./src

vpath %.c $(SRCPATH)

vpath %.h $(LIBPATH)

.PHONY : all clean

all: $(BIN)

$(BIN) : $(OBJ)
		gcc $(FLAGS) $^ $(LIB) -o $@

main.o: fill_matrix_snail.h print_reverse_arr.h stepped_matrix.h mymatrix.h

fill_matrix_snail.o : fill_matrix_snail.h

print_reverse_arr.o : print_reverse_arr.h

stepped_matrix.o : stepped_matrix.h

mymatrix.o : mymatrix.h

clean : 
		rm  matrixTask $(OBJ) 
