/**
 * This program prints integers up to the input value
 * and prints whether or not they are prime.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  int n;
  int i;
  int j;
  int isPrime = 0;    //flag variable

printf("Enter a number to check for primality of intergers up to that value: ");
scanf("%d", &n);

//Use nested for loop. One to print results as you iterate through n, and another to check if prime as you iterate.
//Brain block can't figure out math for the life of me.
  for(i=2; i<=n; i++) {

    for (j = 2; j < i; j++) {

      if ( j % i == 0) {

        break;

      }
      else {

        isPrime = 1;

      }

    }

    if(isPrime) {
      printf("%d is prime\n", i);
    }
    else {
      printf("%d is composite\n", i);
    }

  }



  return 0;
}
