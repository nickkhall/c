#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"
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

	Employee* employees[rows];	

	for (int y = 0; y < rows; y++) {
		// create new employee per row
		Employee* temp_emp = (Employee*)malloc(sizeof(Employee*));

		temp_emp->id = PQgetvalue(res, 0, 0);
		temp_emp->first = PQgetvalue(res, 0, 1);
		temp_emp->last = PQgetvalue(res, 0, 2);
		temp_emp->email = PQgetvalue(res, 0, 3);
		temp_emp->address = PQgetvalue(res, 0, 4);
		temp_emp->phone = PQgetvalue(res, 0, 5);
		temp_emp->start = PQgetvalue(res, 0, 6);
		temp_emp->gender = PQgetvalue(res, 0, 7);
		temp_emp->ethnicity = PQgetvalue(res, 0, 8);
		temp_emp->title = PQgetvalue(res, 0, 9);
		temp_emp->start = PQgetvalue(res, 0, 10);
	}

	disconnect_from_db(conn);
}

