#include <iostream>
#include <ncurses.h>
#include <vector>

#include "headers/menu.hpp"
#include "headers/window.hpp"
#include "headers/interface.hpp"

using namespace std;

int main() {
  // Create window
  Window NewWindow;

  vector<string> mainMenuItems {"Add Review", "List Reviews", "Quit"};
  Menu MainMenu("main", mainMenuItems);

  MainMenu.SetMenuYPosXPos(&NewWindow);

  vector<string> addLabels {"Name", "Address", "Type", "Review", "Items Experienced", "Return Factor"};
  Interface AddInterface(addLabels);

  int curMenu = 0;

  do {
    switch(curMenu) {
      case 0:
        curMenu = MainMenu.PrintMenu(&NewWindow);
        break;
      case 1:
        curMenu = AddInterface.AddMenu(&NewWindow);
        break;
      default:
        break;
    }

  } while (curMenu != -1);

  erase();
  // Close window
  endwin();

  return 0;
}
