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
  
  const short digits[4] = { 
    (*(c_date_string + 11) - 48),
    (*(c_date_string + 12) - 48),
    (*(c_date_string + 14) - 48),
    (*(c_date_string + 15) - 48)
  };
  
  // set day from date string
  char* day = (char*)malloc(sizeof(char) * 5);
  
  for (unsigned short i = 0; i < 5; i++) {
    if (i == 4) *(day + i) = 0x00;
    else *(day + i) = *(c_date_string + i);
  }

  // binary char mappings [0-9]
  const unsigned int digit_masks[10] = {
    1022367, 69905, 991119,
    987935, 630545, 1019679,
    1023775, 987409, 1023903, 561055
  };

  char result_str[200] = {0};
  unsigned short digit_index = 0;
  unsigned short current_index = 0;
  
  for (unsigned short y = 0; y < 5; y++) {
    digit_index = 0;
    for (unsigned short x = 0; x < 7; x++) {
      if (x % 2 == 0) {
        const unsigned int cur_digit = digit_masks[(*(digits + digit_index++))];
      
        for (short d = 3; d >= 0; d--) {
          const unsigned int cur_bit_set = cur_digit >> ((4 - y) * 4);
          const unsigned int draw = (cur_bit_set >> d) & 1;
          
          if (draw) {
            *(result_str + current_index) = 120;
            current_index++;
          } else {
            *(result_str + current_index) = 32;
            current_index++;
          }
        } 
      } else if (x == 3 && (y == 1 || y == 3 )) {
          for (unsigned short i = 0; i < 3; i++) {
            if (i == 1) {
              *(result_str + current_index) = 35;
            }  else {
              *(result_str + current_index) = 32;
            }

            current_index++;
          }
      } else {
          for (unsigned short i = 0; i < 3; i++) {
            *(result_str + current_index) = 32;
            current_index++;
          }
      }
    }
    
    *(result_str + current_index) = '\n';
    current_index++;
  }
  
  printf("\n%s", result_str);

  free(day);
  exit(0);
}

