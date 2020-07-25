#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>

#include <string.h>

struct Employee {
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
};

#endif

