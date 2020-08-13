#include <ncurses.h>
#include <stdlib.h>

#include "headers/window.h"

void window_initialize_windows(Window* win) {
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  win = (Window*) malloc(sizeof(Window));
  if (!win || win == NULL) {
    printf("ERROR:: Failed to allocate memory for Window* win in window_initialize_windows\n");
    free(win);
    exit(1);
  }

  getmaxyx(stdscr, win->y_max, win->x_max);

  // assign new window instance to Window struct
  win->main_window = newwin(0,0,0,0);
  win->menu_window = derwin(win->main_window,
                            win->y_max,
                            win->x_max,
                            win->y_max - 5,
                            win->x_max - 5);

  box(win->menu_window, 0, 0);

  win->render_window = derwin(win->main_window,
                              win->y_max,
                              win->x_max,
                              win->y_max - 10,
                              win->x_max - 10);

  box(win->render_window, 0, 0);

  keypad(win->menu_window, true);
  keypad(win->render_window, true);

  scrollok(win->render_window, true);
};

void window_refresh(WINDOW* win) {
  wrefresh(win);
};

void window_clear(WINDOW* win) {
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

