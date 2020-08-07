#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>

extern const char* employee_labels_mini[];

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
  int* salary;
  struct Employee* next_employee;
} Employee;

Employee* employee_push(Employee* employee, char** data);

Employee* employee_populate(Employee* employee, char** data);

Employee* employee_update(Employee* employee, const char** data);

Employee* employee_remove(Employee* employee, const char* id);

void employee_destroy(Employee* employee);

Employee* employee_handle_search(const char* const* params, Employee* employee);

#endif

