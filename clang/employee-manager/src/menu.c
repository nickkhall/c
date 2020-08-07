#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#include "headers/menu.h"
#include "headers/window.h"
#include "headers/screen.h"
#include "headers/handlers.h"

char* main_menu_items[] = {
  "  Search  Employee  " ,
  "  Create  Employee  ",
  "  Update  Employee  ",
  "  Remove  Employee  ",
  "       Quit         "
};

Menu* menu_create(Menu* menu) {
  Menu* main_menu = (Menu*) malloc(sizeof(Menu));
  if (!main_menu || main_menu == NULL) {
    printf("ERROR::Failure to allocate memory for main in menu_create\n");
    free(main_menu);
    // @TODO: Create global clean_up function solution for all memory if failure
    exit(1);
  }

  // set default main menu states
  main_menu->highlighted = 0;
  main_menu->state = 0;

  for (int m = 0; m < 5; m++) {
    strcpy(*(main_menu->items + m), *(main_menu_items + m));
  }

  return main_menu;
}

// menu_update
// Updates the menu states for state and highlighted
void menu_update(Menu* menu, int key_code, int items_size) {
  switch(key_code) {
    case 74:
    case 106:
    case KEY_DOWN:
      // Prevent the user from selecting item above the list
      if (menu->highlighted + 1 < items_size) {
        menu->highlighted += 1;
      }
      break;
    case 75:
    case 107:
    case KEY_UP:
      // Prevent user from selecting item below the list
      if (menu->highlighted - 1 > -1) {
        menu->highlighted -= 1;
      }
      break;
    default:
      break;
    };

  menu->state = menu->highlighted + 1;
};

// menu_handle_search
void menu_handle_search(Window* win) {
  screen_print_search_label(win);

  Employee* employee = (Employee*) malloc(sizeof(Employee));
  if (!employee || employee == NULL) {
    printf("ERROR::Failure to assign memory allocation to employee in menu_handle_search\n");
    free(employee);
    exit(1);
  }

  handlers_get_id(win, employee); 

  if (!employee || employee == NULL) {
    printf("ERROR::Failure to assign memory allocation to employee in menu_handle_search\n");
    free(employee);
    exit(1);
  }
  // print employee data to screen
  screen_print_employee(win, employee);

  // wait for user to press "Escape"
  noecho();
  int key = 0;
  if ((key = getch()) != ERR) {
    while(key != 27) {
      key = getch();
    }
  }

  employee_destroy(employee);

  window_clear(win);
}

