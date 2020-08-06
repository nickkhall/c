#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "menu.h"
#include "window.h"
#include "input.h"
#include "screen.h"
#include "handlers.h"
#include "employee.h"

extern const char* main_menu_items[];

typedef struct m {
  short int highlighted;
  short int state;
  const char* items[];
} Menu;

Menu* menu_create(Menu* menu);

void menu_update(Menu* menu, int key_code, int items_size);

void menu_destroy(Menu* menu);

void menu_search_handler();

void menu_create_handler();

void menu_update_handler();

void menu_remove_handler();
#endif
