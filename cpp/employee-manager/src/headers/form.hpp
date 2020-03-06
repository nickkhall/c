#ifndef FORM_H
#define FORM_H

#include <vector>
#include <string>

#include "./window.hpp"

class Form : public Window {
  public:
		std::vector<std::string> form_labels;

    Form(std::vector<std::string> form_labels);

    const std::vector<std::string> create(Window *window, int num_of_fields);

    ~Form();
  private:
    std::vector<std::string> form_values;
};

#endif
