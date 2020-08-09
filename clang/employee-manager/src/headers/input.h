#ifndef INPUT_H
#define INPUT_H

#include "window.h"

char** input_create(Window *window, const char** form_labels, const int *num_of_fields);

char* input_get_search_input(Window* win);

char** input_form_create(Window* win, char** data);

#endif

