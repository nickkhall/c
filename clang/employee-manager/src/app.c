#include "headers/window.h"
#include "headers/menu.h"
#include "headers/screen.h"

int app(Window* win, Menu* main_menu) {
  // run employee-manager until user quits
  do {
    switch(main_menu->state) {
      // main menu idle
      case 0: {
        // print title to screen
        screen_print_title(win->render_window);

        // print main menu
        screen_print_menu(win->menu_window, main_menu, 5);
        break;
      }
      // search employee
      case 1: {
        menu_handle_search(win);

        main_menu->state = 0; 
        break;
      }
      // create employee
      case 2: {
        menu_handle_create(win);

        main_menu->state = 0;
        break;
      }
      // update employee
      case 3: {        
        window_clear(win);
        main_menu->state = 0;
        break;
      }
      // remove employee
      case 4: {
        window_clear(win);
        main_menu->state = 0;
        break;
      }
      // quit
      case 5: {
        window_clear(win);
        main_menu->state = -1;
        break;
      }
      // default to menu idle
      default : {
        window_clear(win);
        main_menu->state = 0;
        break;
      }
    }
  } while (main_menu->state > -1);

  return main_menu->state;
}

