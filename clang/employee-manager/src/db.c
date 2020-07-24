#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "headers/postgres_info.h"

#define MAX_STR_SIZE 100

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
char*** query_db(const char* query, const char* const* queryParams, const int num_of_queries) {
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
		system("reset");
		printf("\n-----------------------------\n%s\n-----------------------------", PQerrorMessage(conn));
		PQclear(res);
		disconnect_from_db(conn);
		exit(1);
	}
	
	int rows = PQntuples(res);
	int cols = PQnfields(res);

	// @TODO: separate this logic into function if successful
	char*** query_data;
	query_data = calloc(rows, sizeof(char**));

	if (query_data == NULL) {
		system("reset");
		printf("failure to allocate heap memory for search emp response");
		PQclear(res);
		disconnect_from_db(conn);
		exit(1);
	}

	for (int r = 0; r < rows; r++) {
		*(query_data + r) = calloc(cols, sizeof(char*));

		for (int c = 0; c < cols; c++) {	
			*(*(query_data + r) + c) = calloc(MAX_STR_SIZE, (sizeof(char)));

			char* value = PQgetvalue(res, r, c);

			*(*(*(query_data + r) + c)) = *value;
		}
	}

	PQclear(res);
	
	// disconnect from db
	disconnect_from_db(conn);

	return query_data;
};

// insert

// delete
