#ifndef HANDLERS_H
#define HANDLERS_H

#include "employee.h"

Employee** get_employees();

Employee* get_employee(const char* const* params); 

Employee* create_employee(Employee* employee);

Employee* update_employee(Employee* employee);

int delete_employee(const char* id);

#endif

