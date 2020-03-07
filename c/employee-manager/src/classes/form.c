#include <ncurses.h>

#include "../headers/window.h"
#include "../headers/form.h"
#include "../headers/employee.h"

char** create(Window *window, char** form_labels, int num_of_fields) {
	// enable cursor
	curs_set(1);

	// print user input to screen
	echo();
	
	int key_code {0};
	char** form_data = (char**)malloc(sizeof(char*) * num_of_fields)

	// iterate over form labels (size of form)
	for (int i = 0; i < num_of_fields; i++) {
		// erase / refresh screen
		werase(window->window);
		refresh();
		wrefresh(window->window);

		// create local variable for storing user input
		char* temp_data;

		// move cursor and print form labels
		mvwprintw(
			window->window,
			window->y_max / 2,
			window->x_max / 2 - (form_labels[i].length() / 2),
			form_labels[i]
		);

		// erase / refresh screen again
		werase(window->window);
		refresh();
		wrefresh(window->window);

		// move cursor to after form_label for user input		
		move(window->y_max / 2, window->x_max / 2 + form_labels[i].length() + 1);

		// get user input
		getnstr(temp_data, 50);

		// after user input, push data onto form_data array
		*(form_data + i) = temp_data;

		// free up form data memory
		free(form_data);
	}

	// erase / refresh screen
	werase(window->window);
	refresh();
	wrefresh(window->window);

	// disable cursor
	curs_set(0);

	return form_data;
};

