#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  time_t current_date;
  char* date_string;

  // get current time
  current_date = time(NULL);

  // if the date is a null pointer (error)
  if (current_date == ((time_t) - 1)) {
    // print time error to screen
    (void) fprintf(stderr, "Failure to obtain the current time.\n");

    // exit with error status 1
    exit(1);
  }

  // convert to local time format
  date_string = ctime(&current_date);

  // if the date is a null pointer (error)
  if (date_string == NULL) {
    // print convert error to screen
    (void) fprintf(stderr, "Failure to convert the current time.\n");

    // exit with error status 1
    exit(1);
  }
  
  // get current time digits from date string
  const short digits[4] = { 
    (*(date_string + 11) - 48),
    (*(date_string + 12) - 48),
    (*(date_string + 14) - 48),
    (*(date_string + 15) - 48)
  };
  
  // binary number mappings [0-9]
  const unsigned int digit_masks[10] = {
    1022367, 69905, 991119,
    987935, 630545, 1019679,
    1023775, 987409, 1023903, 1023761
  };

  char result_str[200] = {0};
  unsigned short digit_index = 0;
  unsigned short current_index = 0;
  
  // iterate rows
  for (unsigned short y = 0; y < 5; y++) {
    // keep track of current digit to render row of
    digit_index = 0;

    // iterate columns
    for (unsigned short x = 0; x < 7; x++) {
      // if the column is even, render number
      if (x % 2 == 0) {
        // get binary mapping of current digit
        const unsigned int cur_digit = digit_masks[(*(digits + digit_index++))];
      
        // iterate per 4 bits
        for (short d = 3; d >= 0; d--) {
          // shift bits until last 4 bits (n times)
          const unsigned int cur_bit_set = cur_digit >> ((4 - y) * 4);

          // check if nth bit set (1-4)
          const unsigned int draw = (cur_bit_set >> d) & 1;
          
          // if current bit is set
          if (draw) {
            // append 'x' char to result string
            *(result_str + current_index) = 120;
            // else append space char to result string
          } else {
            *(result_str + current_index) = 32;
          }

          // increment index counter
          current_index++;
        } 
        // check if we need to render a space or delimiter
      } else if (x == 3 && (y == 1 || y == 3 )) {
          for (unsigned short i = 0; i < 3; i++) {
            // if the index is in the middle
            if (i == 1) {
              // append a '#' char to result string
              *(result_str + current_index) = 35;
              // append a space to result string
            }  else {
              *(result_str + current_index) = 32;
            }

            // increment index counter
            current_index++;
          }
        // if its even, render 3 spaces
      } else {
          for (unsigned short i = 0; i < 3; i++) {
            // append a space to result string
            *(result_str + current_index) = 32;

            // increment index counter
            current_index++;
          }
      }
    }
    
    // append a new line char at end of result string to denote end of row
    *(result_str + current_index) = '\n';

    // increment index counter
    current_index++;
  }
  
  // print out time
  // @NOTE: can have function return char* and then return `result_str`
  printf("\n%s", result_str);

  exit(0);
}

