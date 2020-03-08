compile:
	gcc -Wall -o bin/employee-manager src/main.c src/classes/menu.c src/classes/window.c src/classes/form.c src/classes/uuid.c src/classes/utils.c -lncurses

produce_debug:
	gcc -g -o debug/debug src/main.c src/classes/menu.c src/classes/window.c src/classes/form.c src/classes/uuid.c src/classes/utils.c -lncurses

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

debug:
	make produce_debug && make debug_mode;
