#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include <stdio.h>

#include "headers/employee.h"

#define LINE_SIZE 100

char** convert_emp_to_data(PGresult* res, const int row) {
  char** data = NULL;

  data = (char*) malloc(sizeof(char*) * 11);
  if (!data || data == NULL) exit(1);

  *data = (char*) malloc(sizeof(char) * 33);
  *(data + 1) = (char*) malloc(sizeof(char) * 33);
  *(data + 2)= (char*) malloc(sizeof(char) * 51);
  *(data + 3) = (char*) malloc(sizeof(char) * 101);
  *(data + 4) = (char*) malloc(sizeof(char) * 76);
  *(data + 5) = (char*) malloc(sizeof(char) * 51);
  *(data + 6) = (char*) malloc(sizeof(char) * 51);
  *(data + 7) = (char*) malloc(sizeof(char) * 7);
  *(data + 8) = (char*) malloc(sizeof(char) * 51);
  *(data + 9) = (char*) malloc(sizeof(char) * 51);
  *(data + 10) = (char*) malloc(sizeof(char) * 51);

  for (int col = 0; col < 11; col++) {
    strcpy(*(data + col), PQgetvalue(res, row, col));
  }

  return data;
};

