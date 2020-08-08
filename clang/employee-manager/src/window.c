#include <ncurses.h>
#include <stdlib.h>

#include "headers/window.h"

Window* window_create() {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window* win = (Window*) malloc(sizeof(Window));

  // assign new window instance to Window struct
  win->window = newwin(0,0,0,0);

  keypad(win->window, true);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->window, true);

  return win;
};

void window_refresh(Window *win) {
  refresh();
  wrefresh(win->window);
}

void window_clear(Window *win) {
  wclear(win->window);

  window_refresh(win);
};

void window_destroy(Window* win) {
  curs_set(1);
  echo();

  endwin();
  free(win);
  system("reset");
}

