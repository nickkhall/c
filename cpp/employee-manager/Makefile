compile:
	g++ --std=c++14 -o bin/employee-manager src/main.cpp src/classes/menu.cpp src/classes/window.cpp src/classes/form.cpp src/classes/employee.cpp -lncurses

produce_debug:
	g++ -g -o debug/debug --std=c++14 src/main.cpp src/classes/menu.cpp src/classes/window.cpp src/classes/form.cpp src/classes/employee.cpp -lncurses

debug_mode:
	tmux splitw -h -p 50 "gdbserver :12345 ./debug/debug"; tmux select -t 0; gdb -x ./debug/debug_conf.gdb;

debug:
	make produce_debug && make debug_mode;
