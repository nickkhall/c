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

Employee* push_employee(Employee* employee_head, char** data, unsigned long long int num_of_employees) {
  if (!employee_head || employee_head == NULL) {
    printf("ERROR:: create_employee received a bad pointer: %p\n", employee_head);
    free(employee_head);
    exit(1);
  }

  Employee* head = NULL;
  head = (Employee*) malloc(sizeof(Employee));
  if (!head || head == NULL) exit(1);

  // allocate memory for employee data
  head->id                = (char*) malloc(sizeof(char) * 33);
  head->first             = (char*) malloc(sizeof(char) * 51);
  head->last              = (char*) malloc(sizeof(char) * 51);
  head->email             = (char*) malloc(sizeof(char) * 76);
  head->address           = (char*) malloc(sizeof(char) * 76);
  head->phone             = (char*) malloc(sizeof(char) * 51);
  head->start             = (time_t) malloc(sizeof(time_t));
  head->gender            = (char*) malloc(sizeof(char) * 7);
  head->ethnicity         = (char*) malloc(sizeof(char) * 51);
  head->title             = (char*) malloc(sizeof(char) * 51);
  head->salary            = (unsigned long long int) malloc(sizeof(unsigned long long int));
  head->num_of_employees  = (unsigned long long int) malloc(sizeof(unsigned long long int));

  // set next pointer to pointer head
  head->next_employee = employee_head;

  // assign data to employee struct
  head->id                = *(data);
  head->first             = *(data + 1);
  head->last              = *(data + 2);
  head->email             = *(data + 3);
  head->address           = *(data + 4);
  head->phone             = *(data + 5);
  head->start             = (time_t)(data + 6);
  head->gender            = *(data + 7);
  head->ethnicity         = *(data + 8);
  head->title             = *(data + 9);
  head->salary            = (unsigned long long int)(data + 10);
  head->num_of_employees  = num_of_employees;

  // change the current head to new head
  employee_head = head;

  return employee_head;
};

