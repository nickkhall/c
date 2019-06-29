#include <iostream>

#include "headers/menu.hpp"

int main() {
  std::vector<std::string> employee_menu_items {"Add Employee", "Update Employee", "Remove Employee"};
  Menu employee_menu {employee_menu_items};

  employee_menu.PrintMenu();
  return 0;
}
