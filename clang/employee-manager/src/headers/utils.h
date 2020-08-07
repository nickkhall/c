#ifndef UTILS_H
#define UTILS_H

#include <libpq-fe.h>

char** convert_response_to_data(char** data_pointer, PGresult* res, const int row);

#endif

