/**
 * This program plays a guessing game with the user.
 * It selects a random number between 1 and 1000 and
 * prompts the user to guess the value, informing them
 * of whether or not it is higher or lower than the
 * actual value.  Once the user guesses correctly, the
 * game ends and the number of guesses is displayed.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {

  int n = 1000;

  //seed the random number generator
  srand(time(NULL));
  int number = (rand() % n) + 1;

  int guess;
  int num_guesses = 0;

//Title

  printf("Guess-A-Number Game!\n");

//If you just use while you will infinitely loop after one guess
//Use do while so you can terminate after getting the right number
//User input and output within do while loop because it will also infinitely loop if it is outside
    do {

      printf("Enter a number between 1 and %d: ", n);
      scanf("%d", &guess);

      num_guesses ++;

        if (guess < number) {
          printf("Your guess is less than the actual value.\n");
        }
        else if (guess > number) {
          printf("Your guess is higher than the actual value.\n");
        }
        else{
            printf("Congratulations, you found it!  Number of guesses: %d\n", num_guesses);
        }

    } while(guess != number);

  return 0;
}
