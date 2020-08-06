#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>
#include <libpq-fe.h>
#include <string.h>

#include "screen.h"

extern const char* employee_labels_mini[];

typedef struct Employee Employee;

Employee* employee_push(Employee* employee, char** data);

Employee* employee_populate(Employee* employee, char** data);

Employee* employee_update(Employee* employee, const char** data);

Employee* employee_remove(Employee* employee, const char* id);

void employee_destroy(Employee* employee);

#endif

