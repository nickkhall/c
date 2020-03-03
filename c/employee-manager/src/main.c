#include <string.h>
#include <stdio.h>
#include "headers/employee.h"

int main() {
	Employee test_employee = create_employee(
		28,
		"nick",
		"hall",
		"000-111-2222",
		"test@foo.bar",
		'm'
	);

  return 0;
};
