#include "src/headers/postgres_info.h"
#include <stddef.h>
#include <stdio.h>
#include <libpq-fe.h>

// @NOTE: sanitize data
// connect
PGConn* connect_to_db(const char* query) {
	// establish connection to db
	PGConn* conn =  PQconnect(SQL_INFO);

	// if cannot connect to db
	if (conn == NULL) {
		printf("ERROR WITH CONNECTING:\n%s\n", PQerrorMessage(conn));
		exit(1);
	}

	// if connection is bad
	if (PQstatus(conn) != CONNECTION_OK) {
		printf("ERROR: CONNECTION NOT OKAY:\n%s\n", PQerrorMessage(conn));
		exit(1);
	}
	// disconnect from db
	return conn;
}

// search

// insert

// delete

// disconnect
void disconnect_from_db(PGConn* conn) {
	PQfinish(conn);
}

