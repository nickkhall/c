#include <ncurses.h>

#include "headers/employee.h"
#include "headers/window.h"

void print_employee(Window* win, struct Employee* employees, const int rows) {
  const char* Employee_Labels[11] = {
    "id",
    "first",
    "last",
    "email",
    "address",
    "phone",
    "start",
    "gender",
    "ethnicity",
    "title",
    "salary"
  };

  for (int y = 0; y < (rows + 1); y++) {
    for (int x = 0; x < 11; x++) {
      mvwprintw(
        win->window,
        ((win->y_max / 2) - (rows + x)),
        ((win->x_max) / 2) - strlen(*(Employee_Labels + x)),
        *(Employee_Labels + x)
      );

      refresh();
      wrefresh(win->window);
    }
  }
}

void print_search_label(Window* win, const char* label) {
  // get length of search form label
  int label_len = strlen(label);

  // clear screen
  clear_screen(win);

  // print search form label
  mvwprintw(win->window, win->y_max / 2, win->x_max / 2 - (label_len / 2) - 1, label);

  refresh();
  wrefresh(win->window);
};
