#include <iostream>
#include <ncurses.h>
#include <vector>

#include "headers/menu.hpp"
#include "headers/window.hpp"
#include "headers/interface.hpp"

using namespace std;

int main() {
  // Create window
  Window window;

  vector<string> mainMenuItems     {"   Add Review   ", "  List Reviews  ", "      Quit      "};
  vector<string> addLabels         {"Name", "Address", "Type", "Review", "Items Experienced", "Return Factor"};
  vector<string> returnMenuItems   {"Return to Main Menu"};
  vector<string> emptyList         {};

  // Create Main Menu class
  Menu MainMenu(mainMenuItems, "empty");
  // Create Add Menu class
  Interface AddInterface(addLabels);
  // Create Establishment list Menu class with data from filepath
  Menu EstablishmentList(emptyList, "data/data.txt");
  // Create Return Menu class
  // Menu ReturnMenu("return", returnMenuItems);

  // Set Main Menu's x position and y position
  // MainMenu.SetMenuYPosXPos(&window);

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
        curMenu = EstablishmentList.PrintMenu(&window, 3, 0);
        break;
      case 3:
        curMenu = -1;
        break;
      default:
        break;
    }
  } while (curMenu != -1);

  erase();
  // Close window
  endwin();

  // Exit program
  return 0;
}
