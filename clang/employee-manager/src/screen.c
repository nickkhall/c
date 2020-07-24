#include <ncurses.h>

#include "headers/window.h"
#include "headers/screen.h"

void print_data(Window* win, const char*** data, const int rows, const int cols) {
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			const char* cur = *(*(data + y) + x);
		}
	}
}

