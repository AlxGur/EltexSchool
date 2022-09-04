CFLAGS := -c

LIB := -lncurses

LIBPATH := lib

SRCPATH := src


SRC :=  add.c find_entry.c \
		print_all.c read_file.c remove.c\
		write_file.c phone_dir.c my_getline.c

OBJ :=  add.o find_entry.o \
		print_all.o read_file.o remove.o\
		write_file.o phone_dir.o my_getline.o

MAIN := main.o

MAINSRC := $(SRCPATH)/main.c

MAINLIB := $(LIBPATH)/find_entry.h $(LIBPATH)/print_all.h $(LIBPATH)/remove.h\
		 $(LIBPATH)/write_file.h $(LIBPATH)/add.h

BIN := PhoneDir

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
