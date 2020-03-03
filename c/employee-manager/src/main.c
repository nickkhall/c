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
	char* menu_items[4] = {"View", "Plus", "Edit", "Void"};

	for (int y = 0; y < c->row - 2; y++) {
		if (y == 0) {
			printf("+");
		}

		for (int x = 0; x < c->col - 1; x++) {
			// Print corners
			if (y == 0) {
				if (x == c->col - 2) {
					printf("+");
				} else printf("-");
			} else if (y == 0 && x == c->col - 1) {
				printf("+");
			} else if () {

			} else {
				printf(" ");
			}
		}

		printf("¦");
	}

  return 0;
};
