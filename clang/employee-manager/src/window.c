#include <ncurses.h>

#include "headers/window.h"

Window* create_window(Window* win) {
 // assign new window instance to Window struct
  win->window = newwin(0,0,0,0);

  keypad(win->window, true);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->window, true); 

  return win;
};

void clear_screen(Window *window) {
  wclear(window->window);
  refresh();
  wrefresh(window->window);
};

