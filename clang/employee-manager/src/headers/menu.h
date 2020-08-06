#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "window.h"

extern const char* main_menu_items[];

typedef struct m {
  short int highlighted;
  short int state;
  const char* items[];
} Menu;

Menu* menu_create(Menu* menu);

void menu_update(Menu* menu, int key_code, int items_size);

// search
void handle_search(Window* win);

// create
// void handle_create();

// update
// void handle_update();

// remove
// void handle_remove();

// quit
// void quit();

#endif
