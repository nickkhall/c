#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <cstring>

using namespace std;

int quit() {
  return 1;
}

void printFrame(WINDOW* window) {
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  box(window, 0, 0);
  sleep(1);
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
  sleep(1);
}

void printMainMenu(WINDOW* window, string choices[3], int highLight) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  refresh();
  wrefresh(window);

  int menuY = yMax / 3;
  int menuX = xMax / 2;

  for(int c = 0; c < 3; c++) {
    // For selected option, turn on attribute reverse,
    // which reverses the color scheme. (white bg, black text)
    if(c == highLight) {
      wattron(window, A_REVERSE);
    }

    // Regardless, move to x,y coord and print option
    mvwprintw(window, menuY + (c + 2), menuX - (strlen(choices[c].c_str()) / 2), choices[c].c_str());
    // Turn off attribute.
    wattroff(window, A_REVERSE);
  }
}

void clearMenu(WINDOW* window) {
  // Max Y and X coordinates for the Window (Full screen Window)
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  refresh();
  wrefresh(window);

  int menuY = yMax / 3;
  int menuX = xMax / 2;

  move(menuY + 2, menuX - (17 / 2));
  wclrtoeol(window);
  move(menuY + 3, menuX - (17 / 2));
  wclrtoeol(window);
  move(menuY + 4, menuX - (17 / 2));
  wclrtoeol(window);
  printFrame(window);
  refresh();
  wrefresh(window);
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

  string choices[3] = {
    "Create Repository",
    "Update Repository",
    "Clone  Repository"
  };

  int choice;
  int highLight = 0;

  printFrame(window);

  do {
    printMainMenu(window, choices, highLight);

    choice = wgetch(window);

    refresh();
    wrefresh(window);

    switch(choice) {
      case KEY_UP:
        highLight--;
        if (highLight == -1) {
          highLight = 0;
        }
        break;
      case KEY_DOWN:
        highLight++;
        if (highLight == 3) {
          highLight = 2;
        }
        break;
      default:
        case
        break;
    }

    if (choice == 10) {

    }

  } while(choice != 27);

  erase();
  // Close window
  endwin();

  return 0;
}
