#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/ioctl.h> // ioctl, TIOCGWINSZ

#include "../headers/menu.h"

struct coords* get_screen_size() {
	struct coords *c = NULL;
	c = (struct coords*) malloc(sizeof(struct coords));

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	c->row = w.ws_row;
	c->col = w.ws_col;

	return c;
};

void print_menu(const char menu_items[16][4], const int row, const int col) {	
	for (int y = 0; y < row - 2; y++) {
		for (int x = 0; x < col; x++) {
			if (y == 0) {
				if (x == 0 || x == col - 1) printf("+");
				else printf("-");
			} else if (y > 0 && y < row - 2 && (x == 0 || x == col - 1)) {
				printf("|");
			} else printf(" ");
		}
	}
};
