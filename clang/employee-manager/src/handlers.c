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

  for (int y = 0; y < rows; y++) { 
    char* id = malloc(sizeof(char) * 33);
    if (!id || id == NULL) exit(1);
    strcpy(id, PQgetvalue(res, y, 0));

    char* first = malloc(sizeof(char) * 51);
    if (!first || first == NULL) exit(1);
    strcpy(first, PQgetvalue(res, y, 1));

    char* last = malloc(sizeof(char) * 51);
    if (!last || last == NULL) exit(1);
    strcpy(last, PQgetvalue(res, y, 2));

    char* email = malloc(sizeof(char) * 101);
    if (!email || email == NULL) exit(1);
    strcpy(email, PQgetvalue(res, y, 3));

    char* address = malloc(sizeof(char) * 76);
    if (!address || address == NULL) exit(1);
    strcpy(address, PQgetvalue(res, y, 4));

    char* phone = malloc(sizeof(char) * 51);
    if (!phone || phone == NULL) exit(1);
    strcpy(phone, PQgetvalue(res, y, 5));

    char* start = malloc(sizeof(char) * 100);
    if (!start || start == NULL) exit(1);
    strcpy(start, PQgetvalue(res, y, 6));

    char* gender = malloc(sizeof(char) * 7);
    if (!gender || gender == NULL) exit(1);
    strcpy(gender, PQgetvalue(res, y, 7));

    char* ethnicity = malloc(sizeof(char) * 51);
    if (!ethnicity || ethnicity == NULL) exit(1);
    strcpy(ethnicity, PQgetvalue(res, y, 8));

    char* title = malloc(sizeof(char) * 51);
    if (!title || title == NULL) exit(1);
    strcpy(title, PQgetvalue(res, y, 9));

    char* salary = malloc(sizeof(char) * 100);
    if (!salary || salary == NULL) exit(1);
    strcpy(salary, PQgetvalue(res, y, 10));

    char** data = (char*)malloc(sizeof(char*) * rows);
    if (!data || data == NULL) exit(1);

    *(data + rows)       = id;
    (*(data + rows) + 1)  = first;
    (*(data + rows) + 2)  = last;
    (*(data + rows) + 3)  = email;
    (*(data + rows) + 4)  = address;
    (*(data + rows) + 5)  = phone;
    (*(data + rows) + 6)  = start;
    (*(data + rows) + 7)  = gender;
    (*(data + rows) + 8)  = ethnicity;
    (*(data + rows) + 9)  = title;
    (*(data + rows) + 10) = salary;

    create_employee(employee_head, rows, data);
  }

  disconnect_from_db(conn);

  return employee_head;
}

