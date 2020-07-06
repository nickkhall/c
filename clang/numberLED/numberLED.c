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


  // binary char mappings [0-9]
  const unsigned int bit_chars[10] = {
    1022367, 559240, 991119,
    1019535, 561049, 1019679,
    1023775, 559247, 1023903, 561055
  };

  char time_result_str[85];
  short head_count = 0;

  for (int d = 0; d < 4; d++) {
    short current_digit = *(time_digits + d);
    short counter = 0;

    for (short y = 0; y < 5; y++) {
      for (short x = 0; x < 4; x++) {
        const short is_bit_set = ((bit_chars[current_digit] >> ((counter + 1) - 1)) & 1); 

        counter++;

        if (is_bit_set) *(time_result_str + head_count) = 120;
        else *(time_result_str + head_count) = 32;

        head_count++;
        if (((y == 4) && (y % 2 == 0) || x == 3)) *(time_result_str + head_count) = '\n';
      }

      head_count++;
    }

    head_count++;
  } 

  printf("%s\nheadcount: %d\n", time_result_str, head_count);

  free(month);
  free(day);
  exit(0);
}

