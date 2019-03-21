#include <iostream>
#include <vector>
#include <string>

#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
  Interface(std::vector<std::string> inputs, std::vector<std::string> labels);

  std::vector<std::string> inputs;
  std::vector<std::string> labels;
};

#endif
