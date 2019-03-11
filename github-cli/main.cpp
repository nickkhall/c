#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <cstring>
#include <cstdlib>

using namespace std;

// ClearScreen: Handles clearing the entire screen
void ClearScreen() {
  clear();
}

// PrintMenu: Handles generating a menu based off a given set of items
void PrintMenu(WINDOW *window, string items[], int size, int *highLighted) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int menuY = yMax / 2;
  int menuX = xMax / 2;

  for(int c = 0; c < size; c++) {
    // For selected option, turn on attribute reverse,
    // which reverses the color scheme. (white bg, black text)
    if(c == *highLighted) {
      wattron(window, A_REVERSE);
    }

    // Regardless, move to x,y coord and print option
    mvwprintw(window, menuY + (c + 2), menuX - (strlen(items[c].c_str()) / 2), items[c].c_str());
    // Turn off attribute.
    wattroff(window, A_REVERSE);
    wrefresh(window);
  }
}

// ChangeMenuChoice: Handles changing the state of the current menu
void ChangeMenuChoice(WINDOW* window, int *choice, int *highLighted) {
  switch(*choice) {
    case KEY_UP:
      *highLighted = *highLighted - 1;
      if (*highLighted == -1) {
        *highLighted = 0;
      }
      break;
    case KEY_DOWN:
      *highLighted = *highLighted + 1;
      if (*highLighted == 3) {
        *highLighted = 2;
      }
      break;
    default:
      break;
  }
}

// PrintFrame: Handles printing the main window frame with the ASCII title art
void PrintFrame(WINDOW* window) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  ClearScreen();
  wrefresh(window);

  box(window, 0, 0);
  sleep(0.5);
  mvwprintw(window, 1, (xMax / 2) - (25 / 2), "Welcome to the Github CLI");
  wrefresh(window);
  mvwprintw(window, 3, (xMax / 2) - (54 / 2),  "  _____ _ _   _           _        _____ _      _____ ");
  mvwprintw(window, 4, (xMax / 2) - (54 / 2),  " / ____(_) | | |         | |      / ____| |    |_   _|");
  mvwprintw(window, 5, (xMax / 2) - (54 / 2),  "| |  __ _| |_| |__  _   _| |__   | |    | |      | |  ");
  mvwprintw(window, 6, (xMax / 2) - (54 / 2),  "| | |_ | | __| '_ \\| | | | '_ \\  | |    | |      | |  ");
  mvwprintw(window, 7, (xMax / 2) - (54 / 2),  "| |__| | | |_| | | | |_| | |_) | | |____| |____ _| |_ ");
  mvwprintw(window, 8, (xMax / 2) - (54 / 2), " \\_____|_|\\__|_| |_|\\__,_|_.__/   \\_____|______|_____|");
  refresh();
  wrefresh(window);
  sleep(0.5);
}

// MainMenu: Handles generating the Main Menu
int MainMenu(WINDOW* window, int* choice, int* highLighted) {
  string choices[3] = {
    "Create Repository",
    "Update Repository",
    "Clone  Repository"
  };

  do {
    PrintMenu(window, choices, 3, highLighted);
    *choice = wgetch(window);
    ChangeMenuChoice(window, choice, highLighted);
  } while (*choice != 27 && *choice != 10);

  if (*choice == 27) {
    return -1;
  }

  if (*highLighted == 0) {
    return 1;
  }

  refresh();
  wrefresh(window);
}

// CreateRepoMenu: Handles the Create Repository Menu
int CreateRepoMenu(WINDOW* window) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  // Clear the screen
  ClearScreen();
  // Print the window frame
  PrintFrame(window);
  wrefresh(window);

  mvwprintw(window, yMax / 2, xMax / 2 - (38 / 2), "Name of repository: (30 character max)");

  // Output what the user types
  echo();
  // Show blinking cursor
  curs_set(1);
  wrefresh(window);

  char* repoName;
  mvwgetnstr(window, (yMax / 2) + 1, (xMax / 2) - (33 / 2), repoName, 30);

  ClearScreen();
  PrintFrame(window);

  mvwprintw(window, yMax / 2, xMax / 2 - (38 / 2), "Github Username:");

  wrefresh(window);

  char* username;
  mvwgetnstr(window, (yMax / 2) + 1, (xMax / 2) - (50 / 2), username, 50);
  curs_set(0);

  // char command[500];
  //
  // sprintf(command, "curl -u '%s' https://api.github.com/user/repos -d '{\"name\":\"%s\"}'", *username, *repoName);
  //
  // system(command);

  wrefresh(window);

  mvwprintw(window, yMax / 2, xMax / 2 - (38 / 2), "Github repository successfully created.");
  sleep(3);

  // Remove blinking cursor
  return 0;
}

int main(int argc, char ** argv) {
  // Initialize NCurses screen
  initscr();
  noecho();
  curs_set(0);

  // Create window
  WINDOW* window = newwin(0, 0, 0, 0);
  refresh();

  // Enable arrow keys
  keypad(window, true);

  int menu = 0;
  int highLighted = 0;
  int choice = 0;

  do {
    PrintFrame(window);

    switch(menu) {
      case 0:
        menu = MainMenu(window, &choice, &highLighted);
        break;
      case 1:
        menu = CreateRepoMenu(window);
        break;
      default:
        break;
    }
  } while(menu != -1);

  erase();
  // Close window
  endwin();

  return 0;
}
