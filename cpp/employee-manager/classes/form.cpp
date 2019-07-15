#include <ncurses.h>
#include <vector>

#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form() {};

int Form::Create(const std::vector<std::string> &form_items) {
  int key_code {0};

  curs_set(1);
	unsigned int cur_item {0};
	std::vector<char*> inputs {};
		 
  do {
    ClearScreen();
    mvwprintw(window, y_max / 2, x_max - (19 / 2), "(100 character max)");

    char *input = (char*)malloc(sizeof(char) * 100);

    // Print out input text
    mvwprintw(window, y_max, x_max - (8 + form_items[cur_item].length()), ("Enter " + form_items[cur_item] + ":  ").c_str());
    refresh();
    wrefresh(window);

    // Get user input
    mvwgetnstr(window, y_max, x_max, input, 100);
    refresh();
    wrefresh(window);

    // Increment counter
    cur_item++;
  } while(cur_item < form_items.size());

	return 0;
};

Form::~Form() {};
