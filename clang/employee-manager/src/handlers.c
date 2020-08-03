#include <libpq-fe.h>
#include <string.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/employee.h"
#include "headers/db.h"
#include "headers/utils.h"

#define SEARCH_QUERY "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1"

char*** get_employee(const char* const* params, char*** employee_data) {
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

  if (rows < 1) {
    printf("NO USERS FOUND! NEED TO IMPLEMENT ERRORS/NOTIFICATIONS\n");
    PQclear(res);

    disconnect_from_db(conn);
    exit(1);
  };
  
  for (int r = 0; r < rows; r++) {
    employee_data = (char***) malloc((sizeof(char*) + (sizeof(char*))) * rows);
    if (!employee_data || employee_data == NULL) exit(1);

    *(employee_data + r) = (char**) malloc(sizeof(char*) * cols);
    if (!*(employee_data + r) || *(employee_data + r) == NULL) exit(1);

    convert_emp_to_data(*(employee_data + r), res, r);  

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

  return employee_data;
}

