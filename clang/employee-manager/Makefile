INCLUDE_DIR = /usr/include
CC = gcc
C_FLAGS = -I$(INCLUDE_DIR)

LIBS = -lm
ODIR = obj

_DEPS = src/headers/*
DEPS = $(patsubst %, $(INCLUDE_DIR)/%, $(_DEPS))

_OBJ = 
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(C_FLAGS)

employee-manager: $(OBJ)
	$(CC) -o $@ $^ $(C_FLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(INCLUDE_DIR)/*~

produce_debug:
	gcc -g -o debug/debug src/main.c src/classes/*.c -lncurses -L/usr/lib/mysql

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

