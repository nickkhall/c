#include <ncurses.h>

#include "headers/window.h"
#include "headers/screen.h"

void print_to_screen(Window* win, const int y, const int x, char** msg, const int msg_size) {
	for (int w = 0; w < msg_size; w++) {	
		for (int c = 0; *(*(msg + w) + (c + 1)) != '\n'; c++) {
			
		}
	}
}

