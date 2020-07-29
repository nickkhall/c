#include <libpq-fe.h>
#include <string.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/employee.h"
#include "headers/db.h"

#define SEARCH_QUERY "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1"

Employee* get_employee(const char* const* params) {
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
  res = PQexecParams(conn, SEARCH_QUERY, 1, NULL, params, NULL, NULL, 0);

  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    system("reset");
    printf("\n--------------------\n%s\n--------------------\n", PQerrorMessage(conn));
    PQclear(res);

    disconnect_from_db(conn);
    exit(1);
  }
  
  const int rows = PQntuples(res);
  const int cols = PQnfields(res);

  Employee* employee_head = malloc(sizeof(Employee));
  if (!employee_head || employee_head == NULL) {
    printf(
        "\n-------------------------------\nERROR::Employee pointer in create employees is %p..\nTRASH!\n-------------------------------\n",
        employee_head
    );

    // release pointer memory
    free(employee_head);
    exit(1);
  }

  for (int c = 0; c < cols; c++) {
    char** data_pointer = (char*) malloc(sizeof(char*) * 11);
    if (!data_pointer || data_pointer == NULL) exit(1);

    data_pointer = convert_emp_to_data(data_pointer, res, c);  

    if (!data_pointer || data_pointer == NULL) {
      printf("ERROR::Failed to allocate memory for data memory for convert employee\n");
      free(data_pointer);
      exit(1);
    }

    push_employee(employee_head, data_pointer);

    free(data_pointer);
  }

  PQclear(res);

  // disconnect from db
  disconnect_from_db(conn);

  return employee_head;
}

