#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>
#include <libpq-fe.h>
#include <string.h>

typedef struct emp {
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

Employee* create_employee(Employee* employee, const int num, char** data);
#endif

