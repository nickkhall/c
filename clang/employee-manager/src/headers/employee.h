#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <time.h>

#include <string.h>

typedef struct e {
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
	unsigned long int salary;
} Employee;

const char* Employee_Labels[11] = {
	"id",
	"first",
	"last",
	"email",
	"address",
	"phone",
	"start",
	"gender",
	"ethnicity",
	"title",
	"salary"
};

#endif

