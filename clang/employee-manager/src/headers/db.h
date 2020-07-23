#ifndef DB_H
#define DB_H

PGconn* connect_to_db();

PGresult* query_db(const char* query, const char* const* queryParams, const int num_of_queries);

void disconnect_from_db(PGconn* conn);

#endif

