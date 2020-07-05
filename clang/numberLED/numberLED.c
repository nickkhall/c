/*

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   
; Number Sprites
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

"    _  _     _  _  _  _  _ \n"
"  | _| _||_||_ |_   ||_||_|\n"
"  ||_  _|  | _||_|  ||_| _|\n"

*/


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  // get current terminal window specs
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  // set the x and y for the terminal window
  int row = w.ws_row;
  int col = w.ws_col;

  // time variables
  time_t current_date;
  char* c_date_string;

  // obtain current time
  current_date = time(NULL);

  if (current_date == ((time_t) - 1)) {
      (void) fprintf(stderr, "Failure to obtain the current time.\n");

      exit(1);
  }

  // convert to local time format
  c_date_string = ctime(&current_date);

  if (c_date_string == NULL) {
      (void) fprintf(stderr, "Failure to convert the current time.\n");

      exit(1);
  }

  char* month = (char*)malloc(sizeof(char) * 4);
  char* day = (char*)malloc(sizeof(char) * 4);

  const short time_digits[4] = { 
    (*(c_date_string + 11) - 48),
    (*(c_date_string + 12) - 48),
    (*(c_date_string + 14) - 48),
    (*(c_date_string + 15) - 48)
  };
  
  // set day from date string
  *(day + 0) = *(c_date_string + 0);
  *(day + 1) = *(c_date_string + 1);
  *(day + 2) = *(c_date_string + 2);
  *(day + 3) = 0x00;

  // set month from date string
  *(month + 0) = *(c_date_string + 4);
  *(month + 1) = *(c_date_string + 5);
  *(month + 2) = *(c_date_string + 6);
  *(month + 3) = 0x00;


  // char mappings (binary)
  const int bit_chars[10] = {123, 18, 103, 55, 26, 61, 125, 19, 63, 127};
  const int bit_masks[7] = {1, 2, 4, 8, 16, 32, 64};

  for (int d = 0; d < 4; d++) {
    const short current_digit = *(time_digits + d);
    printf("current_digit: %d\n", current_digit);
    for (short i = 0; i < 8; i++) {
      if ((*(bit_chars + current_digit) >> (i - 1)) & 1) printf("match\n");
    }
  }
  


  free(month);
  free(day);
  exit(0);
}

