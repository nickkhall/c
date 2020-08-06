#ifndef DB_H
#define DB_H

#include "employee.h"

PGconn* db_connect();

PGresult* db_query(const char* query,
									const char* const* queryParams,
									const int num_of_queries);

void db_disconnect(PGconn* conn);

#endif

