#include "../headers/employee.h"
#include "./utils.c"

Employee create_employee(
	int age,
	char* first,
	char* last,
	char* phone,
	char* email,
	char gender
) {
	Employee new_employee = {
		create_uuid(),
		age,
		first,
		last,
		phone,
		email,
		gender
	};

	return new_employee;
};
