#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/db.h"

#define SEARCH_QUERY "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1"

struct Employee* get_employee(const char* const* params) {
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

	struct Employee employees[rows];	

	for (int y = 0; y < rows; y++) {
		employees[y].id =					(char*)*(PQgetvalue(res, y, 0));
		employees[y].first =			(char*)*(PQgetvalue(res, y, 1));
		employees[y].last =				(char*)*(PQgetvalue(res, y, 2));
		employees[y].email =			(char*)*(PQgetvalue(res, y, 3));
		employees[y].address =		(char*)*(PQgetvalue(res, y, 4));
		employees[y].phone =			(char*)*(PQgetvalue(res, y, 5));
		employees[y].start =			(time_t)*(PQgetvalue(res, y, 6));
		employees[y].gender =			(char*)*(PQgetvalue(res, y, 7));
		employees[y].ethnicity =	(char*)*(PQgetvalue(res, y, 8));
		employees[y].title =			(char*)*(PQgetvalue(res, y, 9));
		employees[y].salary =			(unsigned long long int)*(PQgetvalue(res, y, 10));
	}

	disconnect_from_db(conn);

	return employees;
}

