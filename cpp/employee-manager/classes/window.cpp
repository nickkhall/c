#include <ncurses.h>

#include "../headers/window.hpp"

Window::Window() {
  initscr();
  noecho();
  curs_set(0);

  window = newwin(0,0,0,0);

  keypad(window, true);

  getmaxyx(stdscr, y_max, x_max);
  scrollok(window, true);
};


