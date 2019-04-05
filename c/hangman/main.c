#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define LENGTH 500

void printStatus(size_t wordCount, unsigned int guess) {
  system("clear");
 
  printf("Welcome to hangman.\nEvery word will be a car manufacture and model.\nThe current word is %zu characters long.\n\nGuess: %d\n\nPlease guess a character\n\nCharacter: ", wordCount, guess);
}

void getUserChar(char* c, unsigned int* guess) {
  *c = getchar();
  *guess = *guess + 1;
}

int main() {
  char words[50][500];
  FILE* wordlist = fopen("words.txt", "r");
  int i = 0;
  int total = 0;
  int guess = 0;

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
    printStatus(wordCount, guess);
    getUserChar(&c, &guess);
  }

  return 0;
};
