#include <iostream>
#include <vector>
#include <string>

#ifndef ESTABLISHMENT_H
#define ESTABLISHMENT_H

class Establishment {
public:
  Establishment();

  std::string name;
  std::string address;
  std::string type;
  int review;
  std::vector<std::string> itemsExperienced;
  bool returnFactor;
};

#endif
