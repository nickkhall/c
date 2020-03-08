#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string.h>

typedef struct e {
	const unsigned long int employee_id;
	char** first_name;
	char** middle_name;
	char** last_name;
	char** suffix;
	char** email_address;
	char** address;
	char** home_phone_number;
	char** cell_phone_number;
	char** marital_status;
	char** social_security_number;
	unsigned long long int start_date;
	char** emergency_contact;
	char** gender;
	char** ethnicity;
	char** residency;
	char** job_title;
	unsigned long int salary;
} employee;

#endif

