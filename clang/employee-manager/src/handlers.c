#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"
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

  Employee** employees = malloc(sizeof(Employee*) * rows);

  for (int y = 0; y < rows; y++) {
    Employee emp = { 
      PQgetvalue(res, y, 0),
      PQgetvalue(res, y, 1),
      PQgetvalue(res, y, 2),
      PQgetvalue(res, y, 3),
      PQgetvalue(res, y, 4),
      PQgetvalue(res, y, 5),
      PQgetvalue(res, y, 6),
      PQgetvalue(res, y, 7),
      PQgetvalue(res, y, 8),
      PQgetvalue(res, y, 9),
      PQgetvalue(res, y, 10)
    };

    Employee* emp_ptr = &emp;

    *(employees + y) = emp_ptr;
  }

  disconnect_from_db(conn);

  return employees;
}

