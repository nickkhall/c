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
SRC = main.c $(wildcard src/*.c)

# All .o files go to build dir
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

# gcc/clang will create .d files containing deps
DEP = $(OBJ:%.o=%.d)

# default target named after binary
$(BIN) : $(BUILD_DIR)/$(BIN)

# Actual target of the binary - depends on all .o files
$(BUILD_DIR)/$(BIN) : $(OBJ)
	# create build dir's - same structure as sources
	mkdir -p $(@D)
	# just link all the object files
	$(CC) $(CFLAGS) $^ -o $@

# include all .d files
-include $(DEP)


# build target for every single object file
# @NOTE: the dependency on header files is covered
# by calling `-include $(DEP)`
$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
	# the -MMD flag additionally adds a .d file with
	# the same name as the .o file
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# prevent confusion with any files named "clean"
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR)/$(BIN) $(OBJ) $(DEP)

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

