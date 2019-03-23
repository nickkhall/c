#include <iostream>
#include <vector>
#include <string>

#ifndef MENU_H
#define MENU_H

#include "./window.hpp"

class Menu {
private:
  std::vector<std::string> items;
  int selected;

public:
  int highlighted;

	Menu(std::vector<std::string> items, std::string filepath);

  // Getters
  int GetMenuSelected();

  // Setters
  void SetMenuSelected(int keyCode);
  int PrintMenu(Window* window, int yDividend, int xDividend);

  void PopulateItemsFromFile(std::string filename);
};

#endif
