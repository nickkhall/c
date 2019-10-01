#include <ncurses.h>
#include <vector>

#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form() {};

void Form::Create(const std::vector<std::string> &form_items) {
  int key_code {0};

  curs_set(1);
	echo();
	unsigned int cur_item {0};

	curs_set(0);
};

Form::~Form() {};
