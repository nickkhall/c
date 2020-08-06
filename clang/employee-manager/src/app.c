//#include "headers/window.h"
//#include "headers/menu.h"

int app(Window* win, Menu* main_menu) {
  // run employee-manager until user quits
  do {
    print_border(win);

    switch(main_menu->state) {
      // main menu idle
      case 0: {
        // print title to screen
        screen_print_title(win);

        // print main menu
        screen_print_main_menu(win,
                        &main_menu,
                        main_menu_items,
                        5);
        break;
      }
      // search employee
      case 1: {
        handle_search(win);

        main_menu->state = 0; 
        break;
      }
      // create employee
      case 2: {
        window_clear_screen(win);
        main_menu->state = 0;
        break;
      }
      // update employee
      case 3: {        
        window_clear_screen(win);
        main_menu->state = 0;
        break;
      }
      // remove employee
      case 4: {
        window_clear_screen(win);
        main_menu->state = 0;
        break;
      }
      // quit
      case 5: {
        window_clear_screen(win);
        main_menu->state = -1;
        break;
      }
      // default to menu idle
      default : {
        window_clear_screen(win);
        main_menu->state = 0;
        break;
      }
    }
  } while (main_menu->state > -1);

  return main_menu->state;
}

