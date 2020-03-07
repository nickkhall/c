#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h"

struct Window {
	unsigned int y_max;
	unsigned int x_max;

	WINDOW *window;
};

void print_header();
void clear_screen();

#endif

