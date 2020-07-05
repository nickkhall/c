#ifndef FORM_H
#define FORM_H

#include <string.h>

#include "./window.h"

typedef struct f {
	char** form_labels;
	char** form_data;
} Form;

char** create(Window *window, const char** form_labels, const int *num_of_fields);

#endif

