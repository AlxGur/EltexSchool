CFLAGS := -c

LIBPATH := lib

SRCPATH := src


SRC := my_sh.c parse.c

OBJ := my_sh.o parse.o

BIN := MySh

.PHONY : all create_dir clean

all: $(BIN)

$(BIN) : $(OBJ)
	gcc $(OBJ) -o $(BIN) 

my_sh.o : $(SRCPATH)/my_sh.c $(LIBPATH)/parse.h
	gcc $(CFLAGS) $< -o $@

parse.o : $(SRCPATH)/parse.c $(LIBPATH)/parse.h
	gcc $(CFLAGS) $< -o $@

clean : 
		rm $(OBJ) $(BIN)
