#include <stdlib.h>
#include <stdio.h>

#include "headers/employee.h"

Employee* create_employee_pointer() { 
  Employee* emp_ptr = (Employee*)malloc(sizeof(Employee));
  if (!emp_ptr) {
    free(emp_ptr);
    printf("ERROR::Failue to allocate memory for emp_ptr in get_employee");
    exit(1);
  }

  emp_ptr->id         = (char*)malloc(sizeof(char) * 33);
  emp_ptr->first      = (char*)malloc(sizeof(char) * 100);
  emp_ptr->last       = (char*)malloc(sizeof(char) * 100);
  emp_ptr->email      = (char*)malloc(sizeof(char) * 100);
  emp_ptr->address    = (char*)malloc(sizeof(char) * 100);
  emp_ptr->phone      = (char*)malloc(sizeof(char) * 33);
  emp_ptr->start      = (time_t)malloc(sizeof(time_t));
  emp_ptr->gender     = (char*)malloc(sizeof(char) * 7);
  emp_ptr->ethnicity  = (char*)malloc(sizeof(char) * 100);
  emp_ptr->title      = (char*)malloc(sizeof(char) * 100);
  emp_ptr->salary     = (unsigned long long int)malloc(sizeof(unsigned long long int));

  return emp_ptr;
};
