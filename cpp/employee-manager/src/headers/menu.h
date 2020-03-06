#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "../headers/window.h"

typedef struct m {
	char** items;
	short int highlighted;
	short int state;
} Menu;

const int render_menu(Window *window);
const short int* get_state() const;
void update_state(int state);
void handle_navigation(int key_code);

#endif
