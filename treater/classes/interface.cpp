#include <ncurses.h>
#include <vector>
#include <string>

#include "../headers/interface.hpp"

Interface::Interface(std::vector<std::string> labels) :
  labels {labels}
{};

int Interface::HandleInput(Window* window) {
  int curItem = 0;

  do {
    char input[100];
    mvwprintw(window->windowInstance, window->yMax / 2, window->xMax - (sizeof(labels[curItem]) / 2), ("Enter " + labels[curItem] + " (100 character max): ").c_str());
    std::cin.getline(input, 100);
    inputs.push_back(input);
    curItem++;
  } while(curItem < labels.size());

  for (int i = 0; i < inputs.size(); i++) {
    mvwprintw(window->windowInstance, window->yMax / 2, window->xMax - (sizeof(inputs[i]) / 2), ("Enter " + inputs[i] + " (100 character max): ").c_str());
  }

  return 0;
}
