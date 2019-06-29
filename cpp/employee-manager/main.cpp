#include <iostream>

#include "headers/menu.hpp"
#include "headers/window.hpp"

int main() {
  // Create new NCurses Window instance
  Window window;

  // Create Employee menu items
  std::vector<std::string> employee_menu_items {"Add Employee", "Update Employee", "Remove Employee"};

  // Create new instance of an Employee Menu
  Menu EmployeeMenu {employee_menu_items};

  int current_menu_selected {0};

  do {
    switch(current_menu_selected) {
      case 0:
        current_menu_selected = EmployeeMenu.PrintMenu(&window);

      default:
        current_menu_selected = 0;
        break;
    }
  } while (current_menu_selected != -1);
  return 0;
}
