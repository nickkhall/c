#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 500

struct word {
  char name[LENGTH];
};

void populateWordsList(FILE* file, struct word* w) {
  int i = 0;

  fscanf(file, "%c", &w->name[i]);

  while(w->name[i] != EOF && i < LENGTH) {
    i++;
    fscanf(file, "%c", &w->name[i]);
  }
}

int main() {
  struct word words;
  FILE* wordlist = fopen("words.txt", "r");
  
  populateWordsList(wordlist, &words);
  
  fclose(wordlist);

  printf("%s", words.name);
 
  return 0;
};
