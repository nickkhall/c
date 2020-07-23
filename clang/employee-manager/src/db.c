#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "headers/postgres_info.h"

// @NOTE: sanitize data
// connect
PGconn* connect_to_db() {
	// establish connection to db
	PGconn* conn =  PQconnectdb(SQL_INFO);

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

// disconnect
void disconnect_from_db(PGconn* conn) {
	PQfinish(conn);
}

// search
PGresult* query_db(const char* query, const char* const* queryParams, const int num_of_queries) {
	PGresult* res;
	// create connection with db
	PGconn* conn = connect_to_db();

	res = PQexec(conn, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		PQclear(res);
		disconnect_from_db(conn);
		exit(1);
	}

	PQclear(res);

	res = PQexecParams(conn, query, num_of_queries, NULL, queryParams, NULL, NULL, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		printf("\n\nERROR!\n-----------------------------\n%s\n----------------------", PQerrorMessage(conn));
		PQclear(res);
		disconnect_from_db(conn);
		exit(1);
	}
	
	PGresult* rows = res;

	PQclear(res);
	
	// disconnect from db
	disconnect_from_db(conn);

	return rows;
};

// insert

// delete
