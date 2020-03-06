#include <iostream>

#include "headers/menu.hpp"
#include "headers/window.hpp"
#include "headers/employee.hpp"
#include "headers/form.hpp"

int main() {
  // Create new NCurses Window instance
  Window window;

  // Create Employee menu items
  std::vector<std::string> employee_menu_items {
		"  Search  Employee  " ,
		"  Create  Employee  ",
		"  Update  Employee  ",
		"  Remove  Employee  ",
		"       Quit         "
	};

  // Create new instance of an Employee Menu
  Menu MainMenu {employee_menu_items};

  do {
    switch(*MainMenu.get_state()) {
    	case 0: {
        window.PrintHeader();
				MainMenu.render_menu(&window);
				break;
      }
			case 1: {
				window.ClearScreen();
				std::vector<std::string> temp_form_labels = {
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

				Form TempForm {temp_form_labels};
				
				const std::vector<std::string> emp_data = TempForm.create(&window, 15);

				MainMenu.update_state(0);
				break;
			}
			case 2: {
				window.ClearScreen();
				MainMenu.update_state(0);
				break;
      }
			case 4: {
				window.ClearScreen();
				MainMenu.update_state(-1);
				break;
			}
      default : {
        window.ClearScreen();
        MainMenu.update_state(0);
        break;
      }
    }
  } while (*MainMenu.get_state() > -1);

	printf("\n\nGoodbye...\n");

  // Turn back on cursor
  curs_set(1);
	echo();
	endwin();

  return 0;
}
