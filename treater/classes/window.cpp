#include <ncurses.h>

#include "../headers/window.hpp"

// Default Constructor
Window::Window() {
  initscr();
  noecho();
  curs_set(0);
}

// Sets Max Y and Max X
void Window::SetMaxYX() {
  getmaxyx(stdscr, yMax, xMax);
}

void Window::ConfigureWindow() {
  windowInstance = newwin(0, 0, 0, 0);
  refresh();

  // Enable arrow keys
  keypad(windowInstance, true);
}
