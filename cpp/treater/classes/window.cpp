#include "../headers/window.hpp"

// Default Constructor
Window::Window() {
  initscr();
  noecho();
  curs_set(0);

  windowInstance = newwin(0,0,0,0);

  keypad(windowInstance, true);

  getmaxyx(stdscr, yMax, xMax);
  scrollok(windowInstance, true);
}

void Window::PrintHeader() {
  mvwprintw(windowInstance,  1, (xMax / 2) - (98 / 2), "      ___           ___           ___           ___           ___           ___           ___     ");
  mvwprintw(windowInstance,  2, (xMax / 2) - (98 / 2), "     /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\    ");
  mvwprintw(windowInstance,  3, (xMax / 2) - (98 / 2), "     \\:\\  \\       /::\\  \\       /::\\  \\       /::\\  \\        \\:\\  \\       /::\\  \\       /::\\  \\   ");
  mvwprintw(windowInstance,  4, (xMax / 2) - (98 / 2), "      \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\        \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\  ");
  mvwprintw(windowInstance,  5, (xMax / 2) - (98 / 2), "      /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\       /::\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\ ");
  mvwprintw(windowInstance,  6, (xMax / 2) - (98 / 2), "     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\");
  mvwprintw(windowInstance,  7, (xMax / 2) - (98 / 2), "    /:/  \\/__/ \\/_|::\\/:/  / \\:\\~\\:\\ \\/__/ \\/__\\:\\/:/  /    /:/  \\/__/ \\:\\~\\:\\ \\/__/ \\/_|::\\/:/  /");
  mvwprintw(windowInstance,  8, (xMax / 2) - (98 / 2), "   /:/  /         |:|::/  /   \\:\\ \\:\\__\\        \\::/  /    /:/  /       \\:\\ \\:\\__\\      |:|::/  / ");
  mvwprintw(windowInstance,  9, (xMax / 2) - (98 / 2), "   \\/__/          |:|\\/__/     \\:\\ \\/__/        /:/  /     \\/__/         \\:\\ \\/__/      |:|\\/__/  ");
  mvwprintw(windowInstance, 10, (xMax / 2) - (98 / 2), "                  |:|  |        \\:\\__\\         /:/  /                     \\:\\__\\        |:|  |    ");
  mvwprintw(windowInstance, 11, (xMax / 2) - (98 / 2), "                   \\|__|         \\/__/         \\/__/                       \\/__/         \\|__|    ");

  refresh();
  wrefresh(windowInstance);
}

void Window::ClearScreen() {
  wclear(windowInstance);
}

void Window::ScrollDown() {
  scroll(windowInstance);
  refresh();
  wrefresh(windowInstance);
}
