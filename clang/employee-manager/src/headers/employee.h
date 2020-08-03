#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>
#include <libpq-fe.h>
#include <string.h>

typedef struct Employee {
  char* id;
  char* first;
  char* last;
  char* email;
  char* address;
  char* phone;
  time_t start;
  char* gender;
  char* ethnicity;
  char* title;
  unsigned long long int salary;
  struct Employee* next_employee;
} Employee;

Employee* push_employee(Employee* employee, char** data);

extern const char* employee_labels[];
#endif

