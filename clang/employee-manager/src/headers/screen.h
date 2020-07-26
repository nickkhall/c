#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#include "employee.h"

void print_employee(Window* win, Employee** employees, const int rows);

void print_error(const char* err);

void print_search_label(Window* win, const char* label);

#endif

