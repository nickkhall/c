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
