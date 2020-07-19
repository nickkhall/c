# Compiler, Linker Defines
CC = gcc
CFLAGS = -std=c18 -Wall
LIBPATH = -L/usr/local/pgsql/lib
LDFLAGS = -o $(BIN) $(LIBPATH) $(LIBS)
CFDEBUG = $(CFLAGS) -g -DDEBUG $(LDFLAGS)
RM = /bin/rm -f

# Source, Executable, Includes, Library Defines
INCLUDES_DIR = /usr/include
BIN = employee-manager
BUILD_DIR = bin
HEADERS = $(wildcard ./headers/*.h)
INCLUDES = -I$(INCLUDES_DIR)
LIBS = -lncurses -lpq

# All .c source files
SRC = main.c $(wildcard *.c)

OBJ = $(SRC:.c=.o)

EXECS = $(SRC:%.c=%)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.o.:
	$(CC) $^ $(LIBS) -o $@

# prevent confusion with any files named "clean"
.PHONY: clean
clean:
	-@ $(RM) *.o
	-@ $(RM) $(EXECS)

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

