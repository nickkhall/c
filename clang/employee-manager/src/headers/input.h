#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <string.h>
#include <libpq-fe.h>

#include "window.h"
#include "employee.h"

#define BUFFER_SIZE 100
#define MAX_STR_SIZE 100

extern const char* SEARCH_LABEL;

char** create(Window *window, const char** form_labels, const int *num_of_fields);

char* get_search_input(Window* win);

#endif

