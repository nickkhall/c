#ifndef DB_H
#define DB_H

#include <libpq-fe.h>

#include "employee.h"

PGconn* db_connect();

PGresult* db_query(PGconn* conn,
									const char* query,
									const char* const* queryParams,
									const int num_of_queries);

PGresult* db_query_by_id(const char* const* query_params);

void db_disconnect(PGconn* conn);

#endif

