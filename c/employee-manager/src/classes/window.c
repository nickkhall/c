#include <ncurses.h>

#include "../headers/window.h"

print_header(Window *window, int x_max, int y_max) {
  mvwprintw(window->window, 1, (x_max / 2) - (91 / 2), " ______                 _                         __  __");
  mvwprintw(window->window, 2, (x_max / 2) - (91 / 2), "|  ____|               | |                       |  \\/  |");
  mvwprintw(window->window, 3, (x_max / 2) - (91 / 2), "| |__   _ __ ___  _ __ | | ___  _   _  ___  ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __");
  mvwprintw(window->window, 4, (x_max / 2) - (91 / 2), "|  __| | '_ ` _ \\| '_ \\| |/ _ \\| | | |/ _ \\/ _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|");
  mvwprintw(window->window, 5, (x_max / 2) - (91 / 2), "| |____| | | | | | |_) | | (_) | |_| |  __/  __/ | |  | | (_| | | | | (_| | (_| |  __/ |");
  mvwprintw(window->window, 6, (x_max / 2) - (91 / 2), "|______|_| |_| |_| .__/|_|\\___/ \\__, |\\___|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|");
  mvwprintw(window->window, 7, (x_max / 2) - (91 / 2), "                 | |             __/ |                                      __/ |");
  mvwprintw(window->window, 8, (x_max / 2) - (91 / 2), "                 |_|            |___/                                      |___/");
  refresh();
  wrefresh(window);
};

void clear_screen(Window *window) {
  wclear(window->window);
};

