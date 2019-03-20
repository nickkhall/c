#include <iostream>
#include <ncurses.h>

#include "../headers/window.hpp"

// Default Constructor
Window::Window() {
  initscr();
  noecho();
  curs_set(0);

  windowInstance = newwin(0,0,0,0);

  keypad(windowInstance, true);

  std::cout << "window constructor" << std::endl;

  getmaxyx(stdscr, yMax, xMax);
}
