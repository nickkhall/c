#include <ncurses.h>
#include <vector>
#include <string>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "../headers/interface.hpp"

Interface::Interface(std::vector<std::string> labels) :
  labels {labels}
{};

void Interface::HandleInput(Window* window) {
  curs_set(1);
  echo();
  int curItem = 0;
  int y = (window->yMax / 2);
  int x = (window->xMax / 2);

  do {
    window->ClearScreen();
    mvwprintw(window->windowInstance, y - 2, x - (19 / 2), "(100 character max)");

    char* input = (char*)malloc(sizeof(char) * 100);

    // Print out input text
    mvwprintw(window->windowInstance, y, x - (8 + labels[curItem].length()), ("Enter " + labels[curItem] + ":  ").c_str());
    refresh();
    wrefresh(window->windowInstance);

    // Get user input
    mvwgetnstr(window->windowInstance, y, x, input, 100);
    refresh();
    wrefresh(window->windowInstance);

    // Push user input onto inputs vector
    inputs.push_back(input);
    // Increment counter
    curItem++;
  } while(curItem < labels.size());

  curs_set(0);
  noecho();

  curItem = 0;

  // Clear window
  window->ClearScreen();
}

void Interface::WriteDataToFile() {
  std::ofstream dataFile;
  dataFile.open("data/data.txt", std::ios_base::app);

  // Iterate over labels and user inputs and write to data file.
  for (int i = 0; i < labels.size(); i++) {
    dataFile << labels[i] << ": " << inputs[i] << std::endl;
  }

  dataFile << "------------------------------" << std::endl << std::endl;

  dataFile.close();
}

void Interface::ClearInputs() {
  inputs.clear();
}

int Interface::AddMenu(Window* window) {
  window->ClearScreen();

  HandleInput(window);
  WriteDataToFile();
  ClearInputs();

  return 0;
}
