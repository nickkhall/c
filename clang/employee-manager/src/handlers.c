#include <libpq-fe.h>
#include <stdlib.h>

#include "src/headers/handlers.h"
#include "src/headers/db.h"

void search_employee(const char* query) {
	if (!*(query)) {
		exit(1);
	}

	PGConn* conn = connect_to_db();

	// start transaction block
	PGResult* result = PQexec(conn "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		PQclear(res);
		exit_nicely(conn);
		exit(1);
	}

	// clear result to avoid mem leaks
	PQclear(res);

	// fetch rows from db
	res = PQexec(conn, "DELCARE employee CURSOR FOR select * from employees");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		PQclear(res);
		exit_nicely(conn);
		exit(1);
	}



	disconnect_from_db(conn);
}

