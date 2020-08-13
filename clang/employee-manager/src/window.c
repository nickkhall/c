#include <ncurses.h>
#include <stdlib.h>

#include "headers/window.h"

void window_create_main_window() {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window* win = (Window*) malloc(sizeof(Window));

  // assign new window instance to Window struct
  win->main_window = newwin(0,0,0,0);

  keypad(win->main_window, true);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->main_window, true);
};

void window_create_menu_window() {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window* win = (Window*) malloc(sizeof(Window));

  // assign new window instance to Window struct
  win->menu_window = newwin(0,0,0,0);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->menu_window, true);
};

void window_create_render_window() {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window* win = (Window*) malloc(sizeof(Window));

  // assign new window instance to Window struct
  win->render_window = newwin(0,0,0,0);

  keypad(win->main_window, true);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->render_window, true);
};

void window_create_stats_window() {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window* win = (Window*) malloc(sizeof(Window));

  // assign new window instance to Window struct
  win->stats_window = newwin(0,0,0,0);

  getmaxyx(stdscr, win->y_max, win->x_max);
  scrollok(win->stats_window, true);
};

void window_refresh(WINDOW* win) {
  wrefresh(win);
};

void window_clear_window(WINDOW* win) {
  wclear(win);

  window_refresh(win);
};

void window_destroy(Window* win) {
  curs_set(1);
  echo();

  endwin();
  free(win);
  system("reset");
}

