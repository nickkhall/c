#include <iostream>
#include <ncurses.h>

#include "../headers/window.hpp"

// Default Constructor
Window::Window() : windowInstance {newwin(0,0,0,0)} {
  initscr();
  noecho();
  curs_set(0);

  keypad(windowInstance, true);
}

// Sets Max Y and Max X
void Window::SetMaxYX() {
  getmaxyx(stdscr, yMax, xMax);
}
