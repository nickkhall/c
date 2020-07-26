#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>
#include <libpq-fe.h>
#include <string.h>

typedef struct {
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
} Employee;

typedef struct {
  Employee employee;
  Employees* next_employee;
} Employees;

// Employee* create_employee_pointer(PGresult* res);
#endif

