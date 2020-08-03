#include <ncurses.h>

#include "headers/window.h"

void clear_screen(Window *window) {
  wclear(window->window);
  refresh();
  wrefresh(window->window);
};

