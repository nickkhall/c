#include <stddef.h>
#include <stdio.h>
#include <libpq-fe.h>

#include "headers/postgres_info.h"

// @NOTE: sanitize data
// connect
PGconn* connect_to_db(const char* query) {
	// establish connection to db
	PGconn* conn =  PQconnect(SQL_INFO);

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
void disconnect_from_db(PGconn* conn) {
	PQfinish(conn);
}

