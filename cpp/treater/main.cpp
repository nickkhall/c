#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <vector>

#include "headers/menu.hpp"
#include "headers/window.hpp"
#include "headers/interface.hpp"

using namespace std;

std::vector<std::string> PopulateItemsFromFile(std::string filepath) {
  std::string line;
  std::ifstream file(filepath);
  std::vector<std::string> items {};

  while (!file.eof()) {
    getline(file, line);
    items.push_back(line);
  }

  file.close();

  return items;
}

int main() {
  // Create window
  Window window;

  vector<string> mainMenuItems     {"   Add Review   ", "  List Reviews  ", "      Quit      "};
  vector<string> addLabels         {"Name", "Address", "Type", "Review", "Items Experienced", "Return Factor"};
  vector<string> returnMenuItems   {"Return to Main Menu"};
  vector<string> emptyList         {};

  // Create Main Menu class
  Menu MainMenu(mainMenuItems);
  // Create Add Menu class
  Interface AddInterface(addLabels);

  std::vector<std::string> items = PopulateItemsFromFile("data/data.txt");
  // Create Establishment list Menu class with data from filepath
  Menu EstablishmentList(items);
  // Create Return Menu class
  // Menu ReturnMenu("return", returnMenuItems); // Will uncomment soon, hold those horses of urs

  // Set current menu to Main Menu
  int curMenu = 0;

  do {
    switch(curMenu) {
      case 0:
        window.PrintHeader();
        curMenu = MainMenu.PrintMenu(&window, 0, 0);
        break;
      case 1:
        curMenu = AddInterface.AddMenu(&window);
        break;
      case 2:
        window.ClearScreen();
        curMenu = EstablishmentList.PrintMenu(&window, 5, 0);
        break;
      case 3:
        curMenu = -1;
        break;
      default:
        curMenu = 0;
        window.ClearScreen();
        break;
    }
  } while (curMenu != -1);

  erase();
  // Close window
  endwin();

  // Exit program
  return 0;
}
