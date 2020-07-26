#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/employee.h"
#include "headers/db.h"

#define SEARCH_QUERY "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1"

Employee** get_employee(const char* const* params) {
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

  Employee** employees = NULL;
  employees = malloc(sizeof(Employee*) * rows);
  if (!employees) {
    free(employees);
    printf("ERROR::Failed to allocate memory for employees list\n");
    exit(1);
  }

  for (int y = 0; y < rows; y++) {
    Employee* employee = create_employee_pointer();

    employee->id        = *(PQgetvalue(res, y, 0));
    employee->first     = *(PQgetvalue(res, y, 1));
    employee->last      = *(PQgetvalue(res, y, 2));
    employee->email     = *(PQgetvalue(res, y, 3));
    employee->address   = *(PQgetvalue(res, y, 4));
    employee->phone     = *(PQgetvalue(res, y, 5));
    employee->start     = *(PQgetvalue(res, y, 6));
    employee->gender    = *(PQgetvalue(res, y, 7));
    employee->ethnicity = *(PQgetvalue(res, y, 8));
    employee->title     = *(PQgetvalue(res, y, 9));
    employee->salary    = *(PQgetvalue(res, y, 10));

    *(employees + y) = employee;
  }

  disconnect_from_db(conn);

  return employees;
}

