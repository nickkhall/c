#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "window.h"

typedef struct m {
  const char** items;
  short int highlighted;
  short int state;
} Menu;

void render_main_menu(Window *window, Menu *menu, const char** items, const int* items_size);

Menu* update_state(Menu *menu, int state);

void handle_navigation(Menu *menu, int key_code, int items_size);

// search
void handle_search(Window* win);

// create
void handle_create();

// update
void handle_update();

// remove
void handle_remove();

// quit
void quit();

#endif
