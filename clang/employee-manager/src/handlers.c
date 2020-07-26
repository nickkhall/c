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
    //PQgetvalue(res, y, 0), PQgetvalue(res, y, 1), PQgetvalue(res, y, 2),
    //PQgetvalue(res, y, 4), PQgetvalue(res, y, 5), PQgetvalue(res, y, 6),
    //PQgetvalue(res, y, 7), PQgetvalue(res, y, 8), PQgetvalue(res, y, 9),
    //PQgetvalue(res, y, 10)
    // Employee* employee = create_employee_pointer();
    
    Employee* employee = malloc(sizeof(Employee));
    if (!employee || employee == NULL) {
      printf("\n-------------------------------\nERROR::Employee pointer in create employees is %p..\nTRASH!\n-------------------------------\n", employee);
      free(employee);
      exit(1);
    }

  employee->id =        (char*)malloc(sizeof(char) *  33);
  employee->first =     (char*)malloc(sizeof(char) *  51);
  employee->last =      (char*)malloc(sizeof(char) *  51);
  employee->email =     (char*)malloc(sizeof(char) * 101);
  employee->address =   (char*)malloc(sizeof(char) *  76);
  employee->phone =     (char*)malloc(sizeof(char) *  51);
  employee->gender =    (char*)malloc(sizeof(char) *   7);
  employee->ethnicity = (char*)malloc(sizeof(char) *  51);
  employee->title =     (char*)malloc(sizeof(char) *  51);

    *(employees + y) = employee;
  }

  disconnect_from_db(conn);

  return employees;
}

