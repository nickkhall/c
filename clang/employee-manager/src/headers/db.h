#ifndef DB_H
#define DB_H

PGconn* connect_to_db();

void disconnect_from_db(PGconn* conn);

#endif

