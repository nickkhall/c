#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>

#include "headers/employee.h"

//Employee* create_employee_pointer(Employee* employee){ 
//  if (!employee || employee == NULL) {
//    printf("\n-------------------------------\nERROR::Employee pointer in create employees is %p..\nTRASH!\n-------------------------------\n", employee);
//    free(employee);
//    exit(1);
//  }
//
//  employee->id =        (char*)malloc(sizeof(char) *  33);
//  employee->first =     (char*)malloc(sizeof(char) *  51);
//  employee->last =      (char*)malloc(sizeof(char) *  51);
//  employee->email =     (char*)malloc(sizeof(char) * 101);
//  employee->address =   (char*)malloc(sizeof(char) *  76);
//  employee->phone =     (char*)malloc(sizeof(char) *  51);
//  employee->gender =    (char*)malloc(sizeof(char) *   7);
//  employee->ethnicity = (char*)malloc(sizeof(char) *  51);
//  employee->title =     (char*)malloc(sizeof(char) *  51);
//
//  //employee->start =     malloc(sizeof(time_t));;
//  // employee->salary =    malloc(sizeof(unsigned long lont int));
//
//  return employee;
//};



/*
 id        | character varying(32)    |           | not null | 
 first     | character varying(50)    |           |          | 
 last      | character varying(50)    |           |          | 
 email     | character varying(100)   |           |          | 
 address   | character varying(75)    |           |          | 
 phone     | character varying(50)    |           |          | 
 start     | timestamp with time zone |           | not null | 
 gender    | character varying(6)     |           |          | 
 ethnicity | character varying(50)    |           |          | 
 title     | character varying(50)    |           |          | 
 salary    | integer                  |           | not null |



// TEST POC FOR FUCKING STRUCT SHITES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct emp {
  char* id;
  char* first;
  char* last;
  struct Employee* next_employee;
} Employee;

Employee* create_employee(Employee* employee, const int* num, char** data) {
  if (!employee || employee == NULL) exit(1);

  for (int e = 0; e < *num; e++) {
    employee->id = *(data);
    employee->first = *(data + 1);
    employee->last = *(data + 2);

    if (e == (*num - 1)) {
      employee->next_employee = NULL;
    } else {
      Employee* next_emp = malloc(sizeof(Employee));
      if (!next_emp || next_emp == NULL) exit(1);
      employee->next_employee = next_emp;
    }
  }

  return employee;
};

int main () {
  int rows = 1;
  int cols = 11;
  Employee* head = NULL;

  head = (Employee*) malloc(sizeof(Employee));
  if (head == NULL) return 1;
  char mock_id[33] = "12345678987654321";
  char mock_first[51] = "tecky";
  char mock_last[51] = "flonkbiCh";

  char* id = malloc(sizeof(char) * 33); // PQgetvalue(res, y, 0);
  if (!id || id == NULL) exit(1);
  strcpy(id, mock_id);
  //*id = *&mock_id;

  char* first = malloc(sizeof(char) * 51); // PQgetvalue(res, y, 0);
  if (!first || first == NULL) exit(1);
  strcpy(first, mock_first);
  // *first = *&mock_first ;

  char* last = malloc(sizeof(char) * 51); // PQgetvalue(res, y, 0);
  if (!last || last == NULL) exit(1);
  strcpy(last, mock_last);
  //*last = *&mock_last;

  //char first[6] = "jicky";              // PQgetvalue(res, y, 1);
  //char last[9] = "pickBiCh";            // PQgetvalue(res, y, 2);

  char* data[3];
  *(data)     = id;
  *(data + 1) = first;
  *(data + 2) = last;

  create_employee(head, &rows, data);

  printf("\nAYE YO BIRTCH!\ncheck this SSSSHite out...\nYou\'re name is %s, and you\'re last name is %s..\nbet you didn\'t know your id was %s you stupid bitch\n", head->first, head->last, head->id);

  free(head);

  return(0);
}
*/
