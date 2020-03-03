#include <string.h>
#include <stdio.h>

#include "headers/employee.h"
#include "headers/menu.h"

int main() {
	Employee test_employee = create_employee(
		28,
		"nick",
		"hall",
		"000-111-2222",
		"test@foo.bar",
		'm'
	);

	struct coords c = get_screen_size();

  return 0;
};
