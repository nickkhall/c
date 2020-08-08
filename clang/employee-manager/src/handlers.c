#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"

#include "headers/db.h"
#include "headers/employee.h"
#include "headers/input.h"
#include "headers/utils.h"
#include "headers/screen.h"
#include "headers/window.h"

Employee* handlers_get_id(Window* win, Employee* employee) {
  // get user input
  const char* user_input = input_get_search_input(win);

  const char* const* query_params = &user_input;

  if (!query_params || query_params == NULL) {
    printf("ERROR: Failure to assign query_params from input_get_search_input in handlers_get_by_id\n");
    exit(1);
  }

  // query db with query params
  PGresult* res = db_query_by_id(query_params);

  // get employee(s) data
  employee = employee_convert(res, query_params, employee);

  if (!employee || employee == NULL) {
    printf("ERROR:: Failed to assign employee data to employee from get_employee in handlers_get_id\n");
    free(employee);
    free(win);
    exit(1);
  }

  return employee;
};

