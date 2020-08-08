#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

#include "headers/postgres_info.h"
#include "headers/db.h"

const char SEARCH_BY_ID_QUERY[] = "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1";

/*
 * -----------------------------------------------------------------------------
 * function: db_query
 * -----------------------------------------------------------------------------
 * params:   
 *         > query          - constant char*
 *         > query_params   - constant pointer pointing to constant char pointer
 *         > num_of_queries - constant integer
 * -----------------------------------------------------------------------------
 * returns:  pointer to PGresult type
 * -----------------------------------------------------------------------------
 */
PGresult* db_query(PGconn* conn,
                  const char* query,
                  const char* const* query_params,
                  const int num_of_queries)
{
  if (!conn || conn == NULL) {
    printf("ERROR:: Failed to connect to postgres db.\n");
    exit(1);
  }

  PGresult* res = PQexec(conn, "BEGIN");
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    PQclear(res);
    db_disconnect(conn);
    exit(1);
  }

  PQclear(res);

  res = PQexecParams(conn,
                    query, num_of_queries,
                    NULL, query_params, NULL,
                    NULL, 0);

  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    system("reset");
    printf("ERROR:: %s\n", PQerrorMessage(conn));
    PQclear(res);
    db_disconnect(conn);
    exit(1);
  }

  PGresult* return_res = NULL;
  return_res = (PGresult*) malloc(PQfsize(res, 1));

  if (!return_res || return_res == NULL) {
    printf("ERROR:: Failed to allocate memory for PGresult res in db_query\n");
    PQclear(res);
    free(return_res);
    free(res);
    db_disconnect(conn);
    exit(1);
  }

  return_res = res;

  PQclear(res);
  // disconnect from db
  db_disconnect(conn);

  return return_res;
};


/*
 * --------------------------------------------------------------------
 * function: db_query_by_id
 * --------------------------------------------------------------------
 * params:   query_params - constant pointer pointing to constant char*
 * --------------------------------------------------------------------
 * returns:  pointer to PGresult type
 * --------------------------------------------------------------------
 */
PGresult* db_query_by_id(const char* const* query_params) {
  PGconn* conn = PQconnectdb(SQL_INFO);
  if (!conn || conn == NULL) {
    printf("ERROR:: Failed to connect to postgres db.\n");
    exit(1);
  }

  if (!query_params || query_params == NULL) {
    printf("ERROR:: Query data is invalid in db_query_by_id");
    db_disconnect(conn);
    exit(1);
  }

  PGresult* res = NULL;
  res = db_query(conn, SEARCH_BY_ID_QUERY, query_params, 1);
  if (!res || res == NULL) {
    printf("ERROR:: Failed to get PQ response from db_query in db_query_by_id\n");
    PQclear(res);
    free(res);
    db_disconnect(conn);
    exit(1);
  }

  db_disconnect(conn);

  return res;
}

/*
 * ---------------------------------------
 * function: db_disconnect
 * ---------------------------------------
 * params  : conn - pointer to PGconn type
 * ---------------------------------------
 * Destroys a connection to a database.
 * ---------------------------------------
 */
void db_disconnect(PGconn* conn) {
  PQfinish(conn);
}
