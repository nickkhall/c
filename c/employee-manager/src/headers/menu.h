#ifndef MENU
#define MENU

struct coords {
	int row;
	int col;
};

struct coords* get_screen_size();

void print_menu(const char menu_items[16][4], const int row, const int col);

#endif
