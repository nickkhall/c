#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "headers/postgres_info.h"
#include "headers/input.h"
#include "headers/screen.h"

/*
 * -----------------------------------------------
 * function: db_connect
 * -----------------------------------------------
 * Creates and returns a connection to a database.
 * -----------------------------------------------
 */
PGconn* db_connect() {
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

/*
 * ----------------------------------------------------------------------------------
 * function: db_connect
 * ----------------------------------------------------------------------------------
 * Queries a database with a given string, given params, and given number of queries.
 * ----------------------------------------------------------------------------------
 * Returns a pointer to the postgres result (PGresult).
 * ----------------------------------------------------------------------------------
 */
PGresult* db_query(const char* query, const char* const* queryParams, const int num_of_queries) {
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

  PGresult* temp = res;

  PQclear(res);
  // disconnect from db
  disconnect_from_db(conn);

  return temp;
};

/*
 * -----------------------------------------------
 * function: db_disconnect
 * -----------------------------------------------
 * Destroys a connection to a database.
 * -----------------------------------------------
 */
void db_disconnect(PGconn* conn) {
  PQfinish(conn);
}
