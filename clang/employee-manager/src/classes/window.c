#include <ncurses.h>

#include "headers/window.h"

void print_header(Window *window) {
	const char* header[] = {
		" ______                 _                         __  __",
		"|  ____|               | |                       |  \\/  |",
		"| |__   _ __ ___  _ __ | | ___  _   _  ___  ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __",
		"|  __| | '_ ` _ \\| '_ \\| |/ _ \\| | | |/ _ \\/ _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|",
		"| |____| | | | | | |_) | | (_) | |_| |  __/  __/ | |  | | (_| | | | | (_| | (_| |  __/ |",
		"|______|_| |_| |_| .__/|_|\\___/ \\__, |\\___|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|",
		"                 | |             __/ |                                      __/ |",
		"                 |_|            |___/                                      |___/"
	};

	for (short int i = 0; i < 8; i++) {
		mvwprintw(window->window, i + 1, (window->x_max / 2) - (91 / 2), *(header + i));
	}

  refresh();
  wrefresh(window->window);
};

void clear_screen(Window *window) {
  wclear(window->window);
  refresh();
  wrefresh(window->window);
};

