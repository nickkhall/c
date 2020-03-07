#include <stdio.h>

#include "headers/menu.h"
#include "headers/window.h"
#include "headers/employee.h"
#include "headers/form.h"

int main() {	
  // create new window
  Window window;

  // create main menu items
	const int main_menu_size = 5;
	const char* main_menu_items[sizeof(char*) * 20][main_menu_size] = {
		"  Search  Employee  " ,
		"  Create  Employee  ",
		"  Update  Employee  ",
		"  Remove  Employee  ",
		"       Quit         "
	};
	char** mmi = main_menu_items;

  // create new menu 
	Menu MainMenu = {mmi, 0, 0};

  do {
    switch(MainMenu.state) {
    	case 0: {
        print_header();
				render_main_menu(&window, &MainMenu, main_menu_items);
				break;
      }
			case 1: {
				clear_screen();
				const char* temp_form_labels[] = {
					"First Name: ",
					"Middle Name: ",
					"Last Name: ",
					"Suffix: ",
					"Email: ",
					"Home Phone: ",
					"Cell Phone: ",
					"Marital Status: ",
					"Social Security: ",
					"Hire Date: ",
					"Emergency Contact: ",
					"Gender: ",
					"Ethnicity: ",
					"Residence: ",
					"Job Title: ",
					"Salary: "
				};


				MainMenu.state = 0;
				break;
			}
			case 2: {
				clear_screen();
				MainMenu.state = 0;
				break;
      }
			case 4: {
				clear_screen();
				MainMenu.state = -1;
				break;
			}
      default : {
				clear_screen();
        MainMenu.state = 0;
        break;
      }
    }
  } while (MainMenu.state > -1);

	printf("\nGoodbye...\n\n");

  // Turn back on cursor
  curs_set(1);
	echo();
	endwin();

  return 0;
};
