#ifndef "DB_H"
#define "DB_H"

PGConn* connect_to_db(const char* query);

void disconnect_from_db(PGConn* conn);

#endif

