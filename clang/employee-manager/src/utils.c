#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "headers/employee.h"

#define LINE_SIZE 100

// @TODO: REMOVE AFTER POST IS UPDATED
/**
 * Writes a series of strings to a file.
 * @param {char**} labels The labels / description of the data.
 * @param {char**} string The string / data to write to the file.
 * @param {int*} size The size of the strings array.
 * @return {void}
 **/
void write_to_file(const char** labels, char **string, const int *size) {
  // create file pointer to data file
  FILE *file = fopen("data/employees.txt", "a");

  // add new line to separate entries
  if (feof(file)) fputs("---------------------------------------------------------------\n", file);
  else fputs("\n---------------------------------------------------------------\n", file);
  
  for (int i = 0; i < *size; i++) {
    // add label
    fputs(*(labels + i), file);
    // add data
    fputs(*(string + i), file);
    // if not end of data
    if (i < *size - 1) {
      // input comma with new line
      fputs(",\n", file);
    }
  }

  // add new line to separate entries
  fputs("\n---------------------------------------------------------------\n", file);

  // close file stream
  fclose(file);
};

char** convert_emp_to_data(Employee* employee) {
  char** data = NULL;
  data = malloc(sizeof(char*) * 11);

  *(data)     = employee->id;
  *(data + 1) = employee->first;
  *(data + 2) = employee->last;
  *(data + 3) = employee->email;
  *(data + 4) = employee->address;
  *(data + 5) = employee->phone;
  *(data + 6) = (char*)employee->start;
  *(data + 7) = employee->gender;
  *(data + 8) = employee->ethnicity;
  *(data + 9) = employee->title;
  *(data + 10) = (char*)employee->salary;

  return data;
};

