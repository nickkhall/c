#ifndef FORM_H
#define FORM_H

#include <string.h>

#include "window.h"

char** create(Window *window, const char** form_labels, const int *num_of_fields);

char* print_search_form(Window* win);

#endif

