#ifndef HANDLERS_H
#define HANDLERS_H

#include "employee.h"

Employee** get_employees();

Employee* get_emp(const char* id); 

Employee* create_emp(Employee* employee);

Employee* update_emp(Employee* employee);

int delete_employee(const char* id);

#endif

