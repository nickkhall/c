#include <string.h>
#include <stdio.h>
#include <ncurses.h>

#include "../headers/menu.h"
#include "../headers/window.h"

const short int* get_state(Menu *menu) {
	return &menu->state;
};

Menu* update_state(Menu *menu, int new_state) {
	menu->state = new_state;
	return menu;
};

void render_main_menu(Window *window,Menu *menu, const char** items, const int* items_size) {
	printf("\033[2J\033[1;1H");

	int key_code = 0;

	do {
		refresh();
		wrefresh(window->window);

		for (int i = 0; i < *items_size; i++) {
			if (i == menu->highlighted) {
				wattron(window->window, A_REVERSE);
			}

			mvwprintw(
				window->window,
				window->y_max / 2 + (i + 2),
				window->x_max / 2 - *items_size,
				*(items + i)
			);

			// Turn off reverse attribute
			wattroff(window->window, A_REVERSE);

			refresh();
			wrefresh(window->window);
		}

		refresh();
		wrefresh(window->window);

		key_code = wgetch(window->window);

		// Update the menu with the currently selected item
		handle_navigation(menu, key_code, *items_size);
	} while (key_code != 27 && key_code != 10); // As long as the user does not hit the "Escape" or "Enter" key
};

void handle_navigation(Menu *menu, int key_code, int items_size) {
	switch(key_code) {
		case KEY_DOWN:
			// Prevent the user from selecting item above the list
			if (menu->highlighted + 1 < items_size) {
				menu->highlighted += 1;
			}
			break;
		case KEY_UP:
			// Prevent user from selecting item below the list
			if (menu->highlighted - 1 > -1) {
				menu->highlighted -= 1;
			}
			break;
		default:
			break;
		};

	menu->state = menu->highlighted + 1;
};


