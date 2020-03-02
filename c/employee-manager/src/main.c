#import <string.h>
#import <stdio.h>
#import "headers/employee.h"

int main() {
	Employee test_employee = create_employee(
		28,
		"nick",
		"hall",
		"000-111-2222",
		"test@foo.bar",
		'm'
	);

	printf(
		"%s %s is approx %d year(s) old. You can reach %s at %s, or at %s.\n",
		test_employee.first,
		test_employee.last,
		test_employee.age,
		((test_employee.gender == 0x6d || test_employee.gender == 0x4d) ? "him" : "her"),
		test_employee.phone,
		test_employee.email
	);

  return 0;
};
