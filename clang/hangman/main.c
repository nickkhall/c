#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define LENGTH 500

void printHeader() {
  printf("+--------------------------------------------------------------------+\n");
  printf("|                   Welcome to the game of Hangman!                  |\n");
  printf("|--------------------------------------------------------------------|\n");
}

void printHumanStatus(int guess) {
  int body[7];

  for (int b = 0; b < 7; b++) {
    body[b] = 32;
  }

  switch(guess) {
    case 0:
      body[6] = 92;
      break;
    case 1:
      body[5] = 47;
      break;
    case 2:
      body[4] = 179;
      break;
    case 3:
      body[3] = 92;
      break;
    case 4:
      body[2] = 47;
      break;
    case 5:
      body[1] = 179;
      break;
    case 6:
      body[0] = 79;
      break;
    default:
      break;
  }

  if (guess == 4) body[guess] = 79;
  else if (guess % 2 == 0) {
    body[guess] = 47;
    body[guess + 1] = 92;
  }
  else body[guess] = 179;

  printf("|                                |                                   |\n");
  printf("|                                %c                                   |\n", body[0]);
  printf("|                               %c %c                                  |\n", body[1], body[2]);
  printf("|                                %c                                   |\n", body[3]);
  printf("|                               %c %c                                  |\n", body[4], body[5]);
  printf("|                     +--------------------+                         |\n");
  printf("|                    /                    /|                         |\n");
  printf("|                   /____________________/ |                         |\n");
  printf("|                  |                     |                           |\n");
  printf("|                  |                     |                           |\n");
  printf("|                                                                    |\n");
  printf("+--------------------------------------------------------------------+\n");
}

void printGameStatus(int score, int guess, int wordCount) {
  int counter = 0;
  // 70 full
  // 68 without border

  for (int i = 0; i < score; i++) {
    if (i == 10 || i == 100 || i == 1000 || i == 10000) {
      counter += 1;
    }
  }
  counter = 0;

  for (int x = 0; x < 68; x++) {
    if (i < 7 + counter) {
      printf("Score: %d", score);
    } else if (i > 7 + counter && i < ) {
      printf("Guess: %d", guess);
    } else if () {
      printf("Word count: %d", wordCount);
    } else {
      printf("%c", 32);
    }
  }
  printf("+--------------------------------------------------------------------+\n");
}

void printGuess() {
  printf("Guess: ");
}

void printStatus(unsigned int score, unsigned int guess, unsigned int wordCount) {
  system("clear");

  printHeader();
  printHumanStatus(guess);
  printGameStatus(score, guess, wordCount);
}

void getUserChar(char* c, unsigned int* guess) {
  *c = getchar();
  *guess = *guess + 1;
}

int main() {
  char words[50][500];
  FILE* wordlist = fopen("words.txt", "r");
  int i = 0;
  int score = 0;
  int total = 0;
  int guess = 7;

  while(fgets(words[i], 500, wordlist)) {
    words[i][strlen(words[i]) - 1] = '\0';
    i++;
  }

  total = i;

  fclose(wordlist);

  const char* randomWord;

  srand((unsigned)time(NULL));
  int randomNumber = rand() % 7;

  randomWord = words[randomNumber];
  size_t wordCount = strlen(randomWord);

  char c;

  while(guess <= (int)wordCount) {
    printStatus(score, guess, wordCount);
    printGuess();
    getUserChar(&c, &guess);
  }

  return 0;
};
