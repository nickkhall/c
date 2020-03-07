#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "../headers/window.h"

typedef struct m {
	char** items;
	short int highlighted;
	short int state;
} Menu;

void render_main_menu(Window *window, Menu *menu, const char** items);
Menu* update_state(Menu *menu, int state);
void handle_navigation(Menu *menu, int key_code, int items_size);

#endif
