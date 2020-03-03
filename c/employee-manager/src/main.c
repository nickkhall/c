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

	int choice = 0;
	struct coords *c = get_screen_size();
	char menu_items[16][4] = {"View", "Plus", "Edit", "Void"};

	print_menu(menu_items, c->row, c->col);

  return 0;
};
