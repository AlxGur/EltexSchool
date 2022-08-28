.PHONY : all create_dir clean

LDFLAGS := -ldl

LIBFLAGS := -shared

CFLAGS := -c -fPIC

LIB := -lncurses

PLUGLIB := -lncurses


DIRPLUG = plugins

LIBPATH := lib

SRCPATH := src


SRC := menu.c load_plugins.c load_plug.c \
		read_dir.c

OBJ := menu.o load_plug.o load_plugins.o\
		 read_dir.o

PLUGOBJ := add.o div.o sub.o mul.o

PLUG := libadd.so libmul.so libdiv.so libsub.so

BIN := CalculatorWithPlugins


vpath %.so $(DIRPLUG)


all: create_dir $(PLUG) $(BIN)

$(BIN) : $(OBJ)
	gcc $(LDFLAGS) $(OBJ) -o $(BIN) $(LIB)

load_plug.o : $(SRCPATH)/load_plug.c $(LIBPATH)/load_plug.h $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

load_plugins.o : $(SRCPATH)/load_plugins.c $(LIBPATH)/load_plugins.h $(LIBPATH)/load_plug.h\
			 $(LIBPATH)/read_dir.h $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

read_dir.o : $(SRCPATH)/read_dir.c $(LIBPATH)/read_dir.h
	gcc $(CFLAGS) $< -o $@

menu.o : $(SRCPATH)/menu.c $(LIBPATH)/struct_for_plug.h $(LIBPATH)/load_plug.h $(LIBPATH)/load_plugins.h
	gcc $(CFLAGS) $< -o $@

add.o : $(SRCPATH)/add.c $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

sub.o : $(SRCPATH)/sub.c $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

div.o : $(SRCPATH)/div.c $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

mul.o : $(SRCPATH)/mul.c $(LIBPATH)/struct_for_plug.h
	gcc $(CFLAGS) $< -o $@

$(DIRPLUG)/libadd.so : add.o
	gcc $(LIBFLAGS) $< -o $@ $(PLUGLIB)

$(DIRPLUG)/libsub.so : sub.o
	gcc $(LIBFLAGS) $< -o $@ $(PLUGLIB)

$(DIRPLUG)/libmul.so : mul.o
	gcc $(LIBFLAGS) $< -o $@ $(PLUGLIB)

$(DIRPLUG)/libdiv.so : div.o
	gcc $(LIBFLAGS) $< -o $@ $(PLUGLIB)

create_dir:
	mkdir $(DIRPLUG)

clean : 
		rm -r $(DIRPLUG)
		rm $(OBJ) $(PLUGOBJ) $(BIN)
