#ifndef INPUT_H
#define INPUT_H

#include "window.h"

char** input_create(Window *window, const char** form_labels, const int *num_of_fields);

const char* const* input_get_search_input(Window* win);

#endif

