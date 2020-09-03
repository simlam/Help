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
  int isPrime;    //flag variable 0 = no, 1 = yes

printf("Enter a number to check for primality of intergers up to that value: ");
scanf("%d", &n);

//Use nested for loop. One to print results as you iterate through n, and another to check if prime as you iterate.
//Brain block can't figure out math for the life of me.
//Figured it out ... if i is divisible by any number j leading up to i, it is not prime, therefore break.
  for(i = 2; i <= n; i ++) {

    for (j = 2; j <= i; j ++) {

      if ( i % j == 0) {

        isPrime = 0;

        break;

      }

    }

    if (i == j) {

      isPrime = 1;

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
