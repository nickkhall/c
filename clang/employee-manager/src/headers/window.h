#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct w {
  unsigned int y_max;
  unsigned int x_max;

  WINDOW *window;
} Window;

Window* create_window(Window* window);
void clear_screen(Window *window);

void screen_refresh(Window* win);

void destroy_window(Window* win);
#endif

