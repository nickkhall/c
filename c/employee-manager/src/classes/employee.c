#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char* create_uuid() {
  char* uid = NULL;
  int min = 0;
  int max = 25;
  int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  char chars[25] = {
    'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p',
    'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z'
  };

  // Set random seed
  srand(time(0));

  for (int i = 0; i < max; i++) {
    int random_seed = (rand() % (min - max + 1)) + min;
    int num = (rand() % (min - max + 1)) + min;

    if (random_seed % 2 == 0) {
      
    } else {
      
    }

    printf("random char: %c\n", chars[num]);
  };

  return uid;
};
