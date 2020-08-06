#include <libpq-fe.h>
#include <string.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/employee.h"
#include "headers/db.h"
#include "headers/utils.h"

// handle_search
// Handles printing search label to the screen,
// getting user input,
// and printing employee data to the screen.
void handle_get_id(Window* win, const char* const* query_params) {
  // print search by id/first/last label
  const char select_query[] = "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1";

  print_search_label(win, SEARCH_LABEL);
  // get user input
  const char* user_input = get_search_input(win);

  // create query params from user input
  const char* const* query_params = &user_input;

  // get employee(s) data
  Employee* employee = NULL;
  employee = get_employee(query_params, employee);
  if (!employee || employee == NULL) exit(1);

  // print employee data to screen
  print_employee(win, employee);

  // wait for user to press "Escape"
  noecho();
  int key = 0;
  if ((key = getch()) != ERR) {
    while(key != 27) {
      key = getch();
    }
  }

  destroy_employees(employee);

  clear_screen(win);
};

