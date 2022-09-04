CFLAGS := -c

LIBPATH := lib

SRCPATH := src


SRC :=  read_file_from_end.c view_pid.c write_read_file.c

OBJ :=  read_file_from_end.o view_pid.o write_read_file.o

MAIN := main.o

MAINSRC := $(SRCPATH)/main.c

MAINLIB := $(LIBPATH)/read_file_from_end.h $(LIBPATH)/view_pid.h $(LIBPATH)/write_read_file.h

BIN := FileIO

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