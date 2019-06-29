#include <vector>
#include <string>
#include <iostream>
#include <ncurses.h>

#include "../headers/menu.hpp"

Menu::Menu(const std::vector<std::string> &menu_items)
  : menu_items {menu_items}
{};

void Menu::PrintMenu() {
  std::cout << "\033[2J\033[1;1H";

};

