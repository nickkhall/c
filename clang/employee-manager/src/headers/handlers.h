#ifndef HANDLERS_H
#define HANDLERS_H

#include "employee.h"

PGresult* handlers_get(const char* const* params);

PGresult* handlers_get_id(const char* const* params);

PGresult* handlers_post(const char* const* params);

PGresult* handlers_put(const char* const* params);

PGresult* handlers_delete(const char* const* params);

#endif

