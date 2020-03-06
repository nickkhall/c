#include <ncurses.h>
#include <vector>

#include "../headers/window.hpp"
#include "../headers/form.hpp"
#include "../headers/employee.hpp"

Form::Form(std::vector<std::string> form_labels)
	: form_labels {form_labels}
{};

const std::vector<std::string> Form::create(Window *window, const int num_of_fields) {
	// enable cursor
	curs_set(1);

	// print user input to screen
	echo();
	
	int key_code {0};

	for (int i = 0; i < num_of_fields; i++) {
		refresh();
		wrefresh(window->window);
		werase(window->window);

		char* temp_data;
		mvwprintw(window->window, window->y_max / 2, window->x_max / 2 - (form_labels[i].length() / 2), form_labels[i].c_str());

		// erase window to re-render
		refresh();
		wrefresh(window->window);
		werase(window->window);
		
		move(window->y_max / 2, window->x_max / 2 + form_labels[i].length() + 1);
		getnstr(temp_data, 50);

		// Convert c string to c++ string	
		std::string s(temp_data);

		// Push onto field data vector the value entered
		form_values.emplace_back(s);
	}

	// erase window to re-render
	refresh();
	wrefresh(window->window);
	werase(window->window);

	// disable cursor
	curs_set(0);

	return 0;
};

Form::~Form() {};
