#include <libpq-fe.h>
#include <stdlib.h>

#include "headers/handlers.h"
#include "headers/db.h"

void search_employee(const char* query) {
	if (!*(query)) {
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
	res = PQexec(conn, "DELCARE employee CURSOR FOR select * from employees");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		PQclear(res);

		PQfinish(conn);
		exit(1);
	}



	disconnect_from_db(conn);
}

