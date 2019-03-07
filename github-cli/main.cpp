#include <iostream>
#include <ncurses.h>

using namespace std;

int main(int argc, char ** argv) {
  // Initialize NCurses screen
  initscr();
  noecho();
  cbreak();

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // Create window
  WINDOW* window = newwin(6, xMax - 12, yMax - 8, 5);
  box(window, 0, 0);
  refresh();
  wrefresh(window);

  // Enable arrow keys
  keypad(window, true);

  string choices[3] = {"Create Repository", "Update Repository", "Clone Repository"};
  int choice;
  int highLight = 0;

  while(1) {
    for(int c = 0; c < 3; c++) {
      // For selected option, turn on attribute reverse,
      // which reverses the color scheme. (white bg, black text)
      if(c == highLight) {
        wattron(window, A_REVERSE);
      }

      // Regardless, move to x,y coord and print option
      mvwprintw(window, c + 2, 10, choices[c].c_str());
      // Turn off attribute.
      wattroff(window, A_REVERSE);
    }

    choice = wgetch(window);

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
        break;
    }

    // If user hits 'Enter' key
    if(choice == 10) {
      // Do things if user hits 'Enter'
      
      // Break out of while loop
      break;
    }
  }

  getch();

  // Close window
  endwin();

  return 0;
}
