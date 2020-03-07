#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct w {
	unsigned int y_max;
	unsigned int x_max;

	WINDOW *window;
} Window;

void print_header(Window *window);
void clear_screen(Window *window);

#endif

