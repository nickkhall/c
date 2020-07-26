#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>

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

Employee* create_employee_pointer();

#endif

