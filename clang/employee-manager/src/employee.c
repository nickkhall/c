#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>

#include "headers/employee.h"

const char* employee_labels_mini[] = {
  "Name",     // 1 / 2
  "Email",    // 3
  "Address",  // 4
  "Phone",    // 6
  "Title"     // 9
};

Employee* push_employee(Employee* employee_head, char** data) {
  if (employee_head == NULL) {
    employee_head = (Employee*) malloc(sizeof(Employee));

    populate_employee_data(employee_head, data);
    employee_head->next_employee = NULL;
  } else {
    Employee* head = NULL;
    head = (Employee*) malloc(sizeof(Employee));
    if (!head || head == NULL) {
      printf("ERROR:: Failure to allocate memory for employee head in push_employee\n");
      free(head);
      free(employee_head);
      exit(1);
    }

    populate_employee_data(head, data);

    head->next_employee = employee_head;
    employee_head = head;
  }

  return employee_head;
};

Employee* populate_employee_data(Employee* employee, char** data) {
  // allocate memory for employee data
  employee->id        = (char*) malloc(sizeof(char) * 33);
  employee->first     = (char*) malloc(sizeof(char) * 51);
  employee->last      = (char*) malloc(sizeof(char) * 51);
  employee->email     = (char*) malloc(sizeof(char) * 76);
  employee->address   = (char*) malloc(sizeof(char) * 76);
  employee->phone     = (char*) malloc(sizeof(char) * 51);
  employee->start     = (time_t) malloc(sizeof(time_t));
  employee->gender    = (char*) malloc(sizeof(char) * 7);
  employee->ethnicity = (char*) malloc(sizeof(char) * 51);
  employee->title     = (char*) malloc(sizeof(char) * 51);
  employee->salary    = (int*) malloc(sizeof(int));

  int* salary = (int*) malloc(sizeof(int));
  if (!salary || salary == NULL) {
    printf("ERROR::Failure to allocate memory for salary in populate_employee_data.\n");
    free(salary);
    exit(1);
  }

  *salary = atoi(*(data + 10));
  // assign data to employee struct
  employee->id        = *(data);
  employee->first     = *(data + 1);
  employee->last      = *(data + 2);
  employee->email     = *(data + 3);
  employee->address   = *(data + 4);
  employee->phone     = *(data + 5);
  employee->start     = (time_t)(data + 6);
  employee->gender    = *(data + 7);
  employee->ethnicity = *(data + 8);
  employee->title     = *(data + 9);
  employee->salary    = salary;

  return employee;
}

void destroy_employees(Employee* employee) {
  while (employee != NULL) {
    free(employee);
    employee = employee->next_employee;
  }
}
