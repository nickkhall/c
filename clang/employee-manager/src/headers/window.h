#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct {
  unsigned int y_max;
  unsigned int x_max;

  WINDOW* window;
  WINDOW* form_window;
} Window;

Window* window_create();

void window_refresh(Window* win);

void window_clear(Window *window);

void window_destroy(Window* win);

#endif

