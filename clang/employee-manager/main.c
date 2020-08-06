#include <libpq-fe.h>
#include <stdio.h>
#include <ncurses.h>

#include "src/headers/employee.h"
#include "src/headers/menu.h"
#include "src/headers/window.h"
#include "src/headers/app.h"

int main() {
  // create window
  Window* win;
  window_create_window(&win);

  Menu *main_menu;
  main_menu = menu_create_menu(main_menu);

  // run application
  while (main_menu->state > -1) {
    employee_manager(&win, &menu);
  }

  // destroy window
  window_destroy_window(&win);
  return 0;
}
