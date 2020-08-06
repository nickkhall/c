#ifndef SCREEN_H
#define SCREEN_H

#include "employee.h"
#include "window.h"
#include "utils.h"

// print_word
// Prints a word to the screen with a given x and y axis
void screen_print_word(Window* win, const int y, const int x, const char* word);

// print_border
// Prints the border to the screen
void screen_print_border(Window* win);

// print_line
// Prints a horizonal line at a given y position
void screen_print_line(Window* win, const int y);

// print_employee_headers
// Prints the Employee table header columns
void screen_print_employee_headers(Window* win);

// print_employee_row
// Prints the Employee table row with Employee data
void screen_print_employee_row(Window* win, Employee* employee, const int row);

// print_employee
// Prints the entire Employees table to the screen
void screen_print_employee(Window* win, Employee* employee);

// print_search_label
// Displays a given search label to the screen
void screen_print_search_label(Window* win, const char* label);

// print_title
// Prints the Employee Manager title to the screen
void screen_print_title(Window* window);

// print_menu
// Prints a menu to the screen
void screen_print_menu(Window *window, Menu* menu, const char** items);

#endif

