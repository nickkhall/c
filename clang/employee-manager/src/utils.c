#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include <stdio.h>

#include "headers/employee.h"

#define LINE_SIZE 100

char** convert_emp_to_data(char** data_pointer, PGresult* res, const int row) {
  for (int col = 0; col < 11; col++) {
    const char* current_pq = PQgetvalue(res, row, col);
    unsigned long int current_pq_length = strlen(current_pq);
    char* current_string = (char*) malloc(sizeof(char) * (current_pq_length + 1));

    strcpy(current_string, current_pq);
    *(data_pointer + col) = current_string;
 }

  return data_pointer;
};

