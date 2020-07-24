#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string.h>

typedef struct e {
	const unsigned long int id;
	char** first;
	char** last;
	char** email;
	char** address;
	char** phone;
	unsigned long long int start;
	char** emergency;
	char** gender;
	char** ethnicity;
	char** title;
	unsigned long int salary;
} Employee;

#endif

