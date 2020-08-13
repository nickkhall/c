#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct {
  unsigned int y_max;
  unsigned int x_max;

  WINDOW* main_window;
  WINDOW* menu_window;
  WINDOW* render_window;
  WINDOW* stats_window;
} Window;

void window_create_main_window();

void window_create_menu_window();

void window_create_render_window();

void window_create_stats_window();

void window_refresh(WINDOW* win);

void window_clear(WINDOW* win);

void window_destroy(Window* win);

#endif

