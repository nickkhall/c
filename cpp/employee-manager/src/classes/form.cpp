#include <ncurses.h>
#include <vector>

#include "../headers/window.hpp"
#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form(std::vector<std::string> form_labels)
	: form_labels {form_labels}
{};

int Form::PrintForm(Window *window, const int num_of_fields) {
	curs_set(1);
	echo();
	
	int key_code {0};
	int y = 2;
  int x = 2;

	do {
    refresh();
    wrefresh(window->window);

    for (int i = 0; i < num_of_fields; i++) {
			char* temp_data;
			mvwprintw(window->window, window->y_max / 2, window->x_max / 2 - (form_labels[i].length() / 2), form_labels[i].c_str());
			move(window->y_max / 2, window->x_max / 2);
			getnstr(temp_data, 50);

			// Convert c string to c++ string	
			std::string s(temp_data);

			// Push onto field data vector the value entered
			form_values.emplace_back(s);
    }

    refresh();
    wrefresh(window->window);

    // Update the menu with the currently selected item
  } while (key_code != 27); // As long as the user does not hit the "Escape" key

	if (key_code == 27) return 0;

	curs_set(0);
};


// std::cout << "\033[2J\033[1;1H";


Form::~Form() {};
