#include <libpq-fe.h>
#include <stdio.h>
#include <ncurses.h>

#include "src/headers/menu.h"
#include "src/headers/window.h"
#include "src/headers/input.h"
#include "src/headers/utils.h"
#include "src/headers/db.h"
#include "src/headers/screen.h"

// main menu items
const int main_menu_size = 5;
const char* main_menu_items[] = {
  "  Search  Employee  " ,
  "  Create  Employee  ",
  "  Update  Employee  ",
  "  Remove  Employee  ",
  "       Quit         "
};

int main() {  
  // initialize screen
  initscr();
  noecho();
  curs_set(0);

  // create Window struct
  Window window;

  // assign new window instance to Window struct
  window.window = newwin(0,0,0,0);

  keypad(window.window, true);

  getmaxyx(stdscr, window.y_max, window.x_max);
  scrollok(window.window, true);

  // create new menu 
  Menu MainMenu = {main_menu_items, 0, 0};

  do {
    print_border(&window);

    switch(MainMenu.state) {
      case 0: {
        print_title(&window);
        render_main_menu(&window, &MainMenu, main_menu_items, &main_menu_size);
        break;
      }
      // search employee
      case 1: {
        handle_search(&window);

        // back to main menu
        MainMenu.state = 0; 
        break;
      }
      // create employee
      case 2: {
        // @TODO: (nickkhall) Refactor me to be a more functional approach, this is a mess
        clear_screen(&window);
        print_border(&window);
        MainMenu.state = 0;
        break;
      }
      // quit
      case 5: {
        clear_screen(&window);
        MainMenu.state = -1;
        break;
      }
      default : {
        clear_screen(&window);
        MainMenu.state = 0;
        break;
      }
    }
  } while (MainMenu.state > -1);

  printf("\nGoodbye...\n\n");

  // Turn back on cursor
  curs_set(1);
  echo();
  endwin();
  system("reset");

  return 0;
}
