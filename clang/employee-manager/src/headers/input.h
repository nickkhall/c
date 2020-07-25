#ifndef INPUT_H
#define INPUT_H

#include <string.h>
#include <libpq-fe.h>

#include "window.h"

char** create(Window *window, const char** form_labels, const int *num_of_fields);

char* get_search_input(Window* win);

void* convert_query_to_data(PGresult* res, const int* rows, const int* cols);

#endif

