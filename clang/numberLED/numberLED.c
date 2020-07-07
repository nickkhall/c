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

  const short digits[4] = { 
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
  const unsigned int bit_masks[10] = {
    1022367, 559240, 991119,
    1019023, 561049, 1019679,
    1023775, 559247, 1023903, 561055
  };

  char time_result_str[104] = {0};
  unsigned short bits = 4;
  unsigned short cur_digit_index = 0;
  
  printf("\n%s\n", c_date_string);

  for (unsigned short y = 0; y < 5; y++) {
    const unsigned int cur_digit = *(digits + cur_digit_index);
    const short n_mask = 15;
    
    for (unsigned short x = 0; x < 7; x++) {
      if (x % 2 == 0) {
        for (unsigned short d = 0; d < 4; d++) {
          const unsigned int cur_bit_set = ((n_mask >> (d + 1)) & 1);
          if (cur_bit_set) {
            printf("x");
          } else printf(" ");
        
        } 
      } else {
        printf(" ");
      }
    }
    
    printf("\n");
    bits += 4;
  }
  
  printf("\n%s", c_date_string);

  free(month);
  free(day);
  exit(0);
}


