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

void Window::PrintHeader() {
  mvwprintw(window, 1, (x_max / 2) - (91 / 2), " ______                 _                         __  __");
  mvwprintw(window, 2, (x_max / 2) - (91 / 2), "|  ____|               | |                       |  \\/  |");
  mvwprintw(window, 3, (x_max / 2) - (91 / 2), "| |__   _ __ ___  _ __ | | ___  _   _  ___  ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __");
  mvwprintw(window, 4, (x_max / 2) - (91 / 2), "|  __| | '_ ` _ \\| '_ \\| |/ _ \\| | | |/ _ \\/ _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|");
  mvwprintw(window, 5, (x_max / 2) - (91 / 2), "| |____| | | | | | |_) | | (_) | |_| |  __/  __/ | |  | | (_| | | | | (_| | (_| |  __/ |");
  mvwprintw(window, 6, (x_max / 2) - (91 / 2), "|______|_| |_| |_| .__/|_|\\___/ \\__, |\\___|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|");
  mvwprintw(window, 7, (x_max / 2) - (91 / 2), "                 | |             __/ |                                      __/ |");
  mvwprintw(window, 8, (x_max / 2) - (91 / 2), "                 |_|            |___/                                      |___/");
  refresh();
  wrefresh(window);
};

void Window::ClearScreen() {
  wclear(window);
};
