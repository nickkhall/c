#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#include "employee.h"

void print_word(Window* win, const int y, const int x, const char* word);

void print_border(Window* win);

void print_screen_line(Window* win, const int y);

void print_employee_headers(Window* win);

void print_employee_row(Window* win, char** data, const int row);

void print_employee(Window* win, Employee* employee);

void print_search_label(Window* win, const char* label);

void print_title(Window *window);

#endif

