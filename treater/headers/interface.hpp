#include <iostream>
#include <vector>
#include <string>

#ifndef INTERFACE_H
#define INTERFACE_H

#include "./window.hpp"

class Interface {
public:
  Interface(std::vector<std::string> labels);

  std::vector<std::string> inputs;
  std::vector<std::string> labels;

  void HandleInput(Window* window);
  void WriteDataToFile();
  void ClearInputs();
  int AddMenu(Window* window);
};

#endif
