#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


char* randomiser();
void toLowerCase();

int main() {
  srand(time(NULL));

  char *rockPaperScissors[3];
  char userInput[10];
  bool isGamePlaying = true;

  rockPaperScissors[0] = "rock";
  rockPaperScissors[1] = "paper";
  rockPaperScissors[2] = "scissors";

  char* cpuInput = randomiser(rockPaperScissors);

  do {
  char endGame;
    printf("Please choose rock, paper, or scissors\n");
    scanf("%s", &userInput );
    printf("You chose: %s\n", userInput);

    toLowerCase(userInput);

    if (strcmp(userInput, cpuInput) == 0) {
      printf("This is a draw\n");
    } else if (strcmp(userInput, "rock") == 0 && strcmp(cpuInput, "scissors") == 0) {
      printf("You win, rock beats scissors\n");
    } else if (strcmp(userInput, "paper") == 0 && strcmp(cpuInput, "rock") == 0) {
      printf("You win, paper beats rock\n");
    } else if (strcmp(userInput, "scissors") == 0 && strcmp(cpuInput, "paper") == 0) {
      printf("You win, scissors beats paper\n");
    } else {
      printf("You lose\n");
    }

    printf("Would you like to continue? (y/n)\n");
    while (getchar() != '\n') {}
    scanf(" %c", &endGame);

    if(endGame == 'y') {
      isGamePlaying = true;
    } else {
       isGamePlaying = false;
    }

  } while (isGamePlaying == true);

  printf("Thank you for playing! See you next time :)");


  return 0;
}

char* randomiser(char *rockPaperScissorsArray[]) {
  const int randomNumberUpToTwo = rand() % 3;
  return rockPaperScissorsArray[randomNumberUpToTwo];
}

void toLowerCase(char str[]) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
}
