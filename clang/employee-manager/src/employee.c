#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>

#include "headers/employee.h"
#include "headers/screen.h"

typedef struct {
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

const char* employee_labels_mini[] = {
  "Name",     // 1 / 2
  "Email",    // 3
  "Address",  // 4
  "Phone",    // 6
  "Title"     // 9
};

/*
 * ----------------------------------------------
 * function: employee_push
 * ----------------------------------------------
 * Creates or adds to a linked list of Employees.
 * ----------------------------------------------
 */
Employee* employee_push(Employee* employee_head, char** data) {
  if (employee_head == NULL) {
    employee_head = (Employee*) malloc(sizeof(Employee));

    populate_employee_data(employee_head, data);
    employee_head->next_employee = NULL;
  } else {
    Employee* head = NULL;
    head = (Employee*) malloc(sizeof(Employee));
    if (!head || head == NULL) {
      printf("ERROR:: Failure to allocate memory for employee head in push_employee\n");
      free(head);
      free(employee_head);
      exit(1);
    }

    populate_employee_data(head, data);

    head->next_employee = employee_head;
    employee_head = head;
  }

  return employee_head;
};

/*
 * -------------------------------------
 * function: employee_populate
 * -------------------------------------
 * Allocates memory for Employee struct, 
 * and assigns it data.
 * -------------------------------------
 */
Employee* employee_populate(Employee* employee, char** data) {
  // allocate memory for employee data
  employee->id        = (char*) malloc(sizeof(char) * 33);
  employee->first     = (char*) malloc(sizeof(char) * 51);
  employee->last      = (char*) malloc(sizeof(char) * 51);
  employee->email     = (char*) malloc(sizeof(char) * 76);
  employee->address   = (char*) malloc(sizeof(char) * 76);
  employee->phone     = (char*) malloc(sizeof(char) * 51);
  employee->start     = (time_t) malloc(sizeof(time_t));
  employee->gender    = (char*) malloc(sizeof(char) * 7);
  employee->ethnicity = (char*) malloc(sizeof(char) * 51);
  employee->title     = (char*) malloc(sizeof(char) * 51);
  employee->salary    = (int*) malloc(sizeof(int));

  int* salary = (int*) malloc(sizeof(int));
  if (!salary || salary == NULL) {
    printf("ERROR::Failure to allocate memory for salary in populate_employee_data.\n");
    free(salary);
    exit(1);
  }

  *salary = atoi(*(data + 10));
  // assign data to employee struct
  employee->id        = *(data);
  employee->first     = *(data + 1);
  employee->last      = *(data + 2);
  employee->email     = *(data + 3);
  employee->address   = *(data + 4);
  employee->phone     = *(data + 5);
  employee->start     = (time_t)(data + 6);
  employee->gender    = *(data + 7);
  employee->ethnicity = *(data + 8);
  employee->title     = *(data + 9);
  employee->salary    = salary;

  return employee;
}

/*
 * ----------------------------------
 * function: employee_update
 * ----------------------------------
 * Updates an Employee by a given ID.
 * ----------------------------------
 */



/*
 * ---------------------------------------------
 * function: employee_destroy
 * ---------------------------------------------
 * Destroys the entire linked list of Employees.
 * ---------------------------------------------
 */
void employee_destroy(Employee* employee) {
  while (employee != NULL) {
    free(employee);
    employee = employee->next_employee;
  }
}

/*
 * -----------------------------------------------------------------
 * function: employee_search_handler
 * -----------------------------------------------------------------
 * Handles querying database and returning linked list of Employees.
 * -----------------------------------------------------------------
 */
// this needs to use db_query to query and return employee data
Employee* employee_search_handler(const char* const* params, Employee* employee) {
  if (!*(params)) {
    exit(1);
  }

  PGconn* conn = connect_to_db();

  // start transaction block
  PGresult* res = PQexec(conn, "BEGIN");
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    PQclear(res);

    PQfinish(conn);
    exit(1);
  }

  // clear result to avoid mem leaks
  PQclear(res);

  // fetch rows from db
  res = PQexecParams(conn,
                    SEARCH_QUERY,
                    1, NULL,
                    params, NULL,
                    NULL, 0);

  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    system("reset");
    printf("\n--------------------\n%s\n--------------------\n", PQerrorMessage(conn));
    PQclear(res);

    disconnect_from_db(conn);
    exit(1);
  }
  
  const int rows = PQntuples(res);
  const int cols = PQnfields(res);

  if (rows < 1) {
    printf("NO USERS FOUND! NEED TO IMPLEMENT ERRORS/NOTIFICATIONS\n");
    PQclear(res);

    disconnect_from_db(conn);
    exit(1);
  };

  unsigned long int employee_size = (sizeof(char*) * rows);
  char*** employee_data = NULL;
  employee_data = (char***) malloc(employee_size);
  if (!employee_data || employee_data == NULL) exit(1);
  
  for (int r = 0; r < rows; r++) {
    *(employee_data + r) = (char**) malloc(sizeof(char*) * cols);
    if (!*(employee_data + r) || *(employee_data + r) == NULL) exit(1);

    convert_response_to_data(*(employee_data + r), res, r);

    employee = push_employee(employee, *(employee_data + r));
    if (!employee || employee == NULL) exit(1);

    // if there is a failure, ABORT
    if (!*(employee_data + r) || *(employee_data + r) == NULL) {
      printf("ERROR::Failed to allocate memory for data memory for convert employee\n");
      
      // free up all data pointer's memory
      for (int rr = 0; rr < rows; rr++)
        for (int d = 0; d < 11; d++) {
          free(*(employee_data + r) + d);
        }

      // free up data memory
      free(employee_data);

      PQclear(res);
      disconnect_from_db(conn);

      exit(1);
    }
  }

  PQclear(res);

  // disconnect from db
  disconnect_from_db(conn);

  return employee;
}
