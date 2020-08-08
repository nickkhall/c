#include <libpq-fe.h>
#include <stdlib.h>
#include <ncurses.h>

#include "src/headers/menu.h"
#include "src/headers/window.h"
#include "src/headers/app.h"

int main() {
  // create window
  Window* win = NULL;
  win = window_create();
  if (!win || win == NULL) {
    free(win);
    return 1;
  }

  Menu* main_menu = NULL;
  main_menu = menu_create_main_menu();
  if (!main_menu || main_menu == NULL) {
    free(main_menu);
    return 1;
  }

  // run application
  while (main_menu->state > -1) {
    app(win, main_menu);
  }

  // destroy window
  window_destroy(win);
  free(main_menu);
  return 0;
}
