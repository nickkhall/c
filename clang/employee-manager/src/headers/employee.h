#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>
#include <libpq-fe.h>
#include <string.h>

#include "employee.h"
#include "screen.h"
#include "menu.h"

typedef struct Employee {
  char* id;
  char* first;
  char* last;
  char* email;
  char* address;
  char* phone;
  time_t start;
  char* gender;
  char* ethnicity;
  char* title;
  int* salary;
  struct Employee* next_employee;
} Employee;

Employee* push_employee(Employee* employee, char** data);

Employee* populate_employee_data(Employee* employee, char** data);

void destroy_employees(Employee* employee);

extern const char* employee_labels_mini[];

int employee_manager(Window* win, Menu* main_menu) {
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

#endif

