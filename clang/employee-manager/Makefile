CC = gcc
INCLUDE = /usr/include/postgresql
INCLUDE_POSTGRES = $(pg_config --includedir)

all: employee-manager

main.o: main.c
	$(CC) -c $(INCLUDE_POSTGRES) $(INCLUDES) main.c

employee-manager: main.o
	$(CC) -o employee-manager main.o $(LIBS)

clean:
	rm -rf employee-manager main.o

compile:
	gcc -Wall -o bin/employee-manager -lncurses -I/usr/local/include/mysql src/main.c src/classes/*.c 

produce_debug:
	gcc -g -o debug/debug src/main.c src/classes/*.c -lncurses -L/usr/lib/mysql

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

