#ifndef HANDLERS_H
#define HANDLERS_H

#include "employee.h"

struct Employee* get_employees();

struct Employee* get_employee(const char* const* params); 

struct Employee* create_employee(struct Employee* employee);

struct Employee* update_employee(struct Employee* employee);

int delete_employee(const char* id);

#endif

