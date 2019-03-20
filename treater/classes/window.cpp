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

void Window::PrintHeader(WINDOW* window) {

  mvwprintw(window,  1, (xMax / 2) - (98 / 2), "      ___           ___           ___           ___           ___           ___           ___     ");
  mvwprintw(window,  2, (xMax / 2) - (98 / 2), "     /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\    ");
  mvwprintw(window,  3, (xMax / 2) - (98 / 2), "     \\:\\  \\       /::\\  \\       /::\\  \\       /::\\  \\        \\:\\  \\       /::\\  \\       /::\\  \\   ");
  mvwprintw(window,  4, (xMax / 2) - (98 / 2), "      \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\        \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\  ");
  mvwprintw(window,  5, (xMax / 2) - (98 / 2), "      /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\       /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\ ");
  mvwprintw(window,  6, (xMax / 2) - (98 / 2), "     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\");
  mvwprintw(window,  7, (xMax / 2) - (98 / 2), "    /:/  \\/__/ \\/_|::\\/:/  / \\:\\~\\:\\ \\/__/ \\/__\\:\\/:/  /    /:/  \\/__/ \\:\\~\\:\\ \\/__/ \\/_|::\\/:/  /");
  mvwprintw(window,  8, (xMax / 2) - (98 / 2), "   /:/  /         |:|::/  /   \\:\\ \\:\\__\\        \\::/  /    /:/  /       \\:\\ \\:\\__\\      |:|::/  / ");
  mvwprintw(window,  9, (xMax / 2) - (98 / 2), "   \\/__/          |:|\\/__/     \\:\\ \\/__/        /:/  /     \\/__/         \\:\\ \\/__/      |:|\\/__/  ");
  mvwprintw(window, 10, (xMax / 2) - (98 / 2), "                  |:|  |        \\:\\__\\         /:/  /                     \\:\\__\\        |:|  |    ");
  mvwprintw(window, 11, (xMax / 2) - (98 / 2), "                   \\|__|         \\/__/         \\/__/                       \\/__/         \\|__|    ");

  wrefresh(window->windowInstance);
}
