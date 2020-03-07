#ifndef FORM_H
#define FORM_H

#include <string.h>

#include "./window.h"

typedef struct f {
	char** form_labels;
	char** form_data;
} Form;

const char** create(Window *window, int num_of_fields);

#endif

