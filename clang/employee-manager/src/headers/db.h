#ifndef DB_H
#define DB_H

#include "employee.h"

PGconn* connect_to_db();

Employee* query_db_by_id(const char* query, const char* const* queryParams, const int num_of_queries);

void disconnect_from_db(PGconn* conn);

#endif

