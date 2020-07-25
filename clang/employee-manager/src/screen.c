#include <ncurses.h>

#include "headers/window.h"
#include "headers/screen.h"
#include "headers/employee.h"

void print_employee(Window* win, Employee** employees, const int rows) {
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < 12; x++) {
			const Employee cur = *(*(employees + y) + x);
			const char* cur_label = *(Employee_Labels + x);
		}
	}
}

