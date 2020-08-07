#include <libpq-fe.h>
#include <string.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/employee.h"
#include "headers/input.h"
#include "headers/utils.h"
#include "headers/screen.h"
#include "headers/window.h"

Employee* handlers_get_id(Window* win, Employee* employee) {
  const char select_query[] = "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1";

  // get user input
  const char* const* user_input = input_get_search_input(win);

  // create query params from user input
  const char* const* query_params = user_input;

  // get employee(s) data
  employee_handle_search(query_params, employee);
  if (!employee || employee == NULL) {
    printf("ERROR:: Failed to assign employee data to employee from get_employee in handlers_get_id\n");
    free(employee);
    free(win);
    exit(1);
  }

  return employee;
};

