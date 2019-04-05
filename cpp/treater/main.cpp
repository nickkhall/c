#include "headers/window.hpp"
#include "headers/menu.hpp"
#include "headers/interface.hpp"

using namespace std;

int main() {
  // Create a window
  Window window;

  // All Menu items
  vector<string> mainMenuItems {
    "   Add Review   ",
    "  List Reviews  ",
    "      Quit      "
  };
  vector<string> addLabels {
    "Name",
    "Address",
    "Type",
    "Review",
    "Items Experienced",
    "Return Factor"
  };
  vector<string> returnMenuItems {"Return to Main Menu"};
  vector<string> emptyList       {};

  // Create Main Menu
  Menu MainMenu(mainMenuItems);
  // Create Add Menu
  Interface AddInterface(addLabels);

  // Create Establishment list Menu
  Menu EstablishmentList(emptyList);
  EstablishmentList.PopulateItemsFromFile("data/data.txt");

  // Set current menu to Main Menu
  int curMenu = 0;

  // While each menu does not return -1
  do {
    switch(curMenu) {
      // Main Menu
      case 0:
        // Print Main Menu's ASCII art
        window.PrintHeader();
        // Print Main Menu
        curMenu = MainMenu.PrintMenu(&window, 0, 0);
        break;
      case 1:
        // If user selects first menu item
        // Start the function to gather users input for place visited
        curMenu = AddInterface.AddMenu(&window);
        break;
        // If the users selects the second menu item
      case 2:
        // Clear the screen
        window.ClearScreen();
        // Read from the data file and print items to the screen
        curMenu = EstablishmentList.PrintMenu(&window, 5, 0);
        break;
      // If the user selects the 3rd menu item (Quit)
      case 3:
        // Quit the while loop to end the program
        curMenu = -1;
        break;
      default:
        // Otherwise, return user to Main Menu
        curMenu = 0;
        // Clear the screen
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
