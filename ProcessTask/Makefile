CFLAGS := -c

LIB := 

LIBPATH := lib

SRCPATH := src


SRC :=  process_tree.c simple_create_process.c

OBJ :=  process_tree.o simple_create_process.o

MAIN := main.o

MAINSRC := $(SRCPATH)/main.c

MAINLIB := $(LIBPATH)/process_tree.h $(LIBPATH)/simple_create_process.h

BIN := ProcessTask

.PHONY : all clean

all:  $(BIN)

$(BIN) : $(OBJ) $(MAIN)
	gcc $(OBJ) main.o -o $(BIN) $(LIB)

$(OBJ) : %.o : $(SRCPATH)/%.c $(LIBPATH)/%.h
	gcc $(CFLAGS) $< -o $@

$(MAIN) : $(MAINSRC)  $(MAINLIB)
	gcc $(CFLAGS) $< -o $@

clean : 
		rm $(OBJ) $(BIN) $(MAIN)