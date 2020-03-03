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
		if (y == 0) {
			printf("+");
		}

		for (int x = 0; x < col - 1; x++) {
			// Print corners
			if (y == 0) {
				if (x == col - 2 || y == row - 3) {
					printf("+");
				} else printf("-");
			} else if ((y == 0 && x == col - 1) || (y == row - 3 && x == col - 2)) {
				printf("+");
			} else if (x == 0 || x == col - 3) {
				printf("¦");
			} else {
				printf(" ");
			}
		}
	}
};
