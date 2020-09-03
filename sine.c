/**
 * This program uses a Taylor Series to compute a value
 * of sine.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * This function computes the factorial function,
 * n! = n * (n-1) * (n-2) ... 3 * 2 * 1
 */
long factorial(int n);

int main(int argc, char **argv) {

  double x;
  int n;
  int i;
  int j;
  double result;

//User inputs

  printf("Enter x to calculate sine of: ");
  scanf("%lf", &x);
  printf("Enter n amount of times to perform the taylor series: ");
  scanf("%d", &n);

//Calculations
//Did you learn multiple increments with one test condition?
//Use j here as the (2i + 1) in the taylor series since i in code equates to number of iterations of the taylor series based off n in code

for (i = 0, j = 1; i <= n; i++, j += 2) {

//This is for the alternating + and - of the taylor series based off of n

    if (i % 2 != 0) {
      result = result - pow(x, j) / factorial(j);
    }
    else {
      result = result + pow(x, j) / factorial(j);
    }

}

  printf("sin(%f) = %f\n", x, result);

  return 0;
}

long factorial(int n) {
  long result = 1, i;
  for(i=2; i<=n; i++) {
    result *= i;
  }
  return result;
}
