
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double a, b, result;
  int choice;

  printf("Enter operand a: ");
  scanf("%lf", &a);

  printf("Enter operand b: ");
  scanf("%lf", &b);

  printf("Enter operation:\n");
  printf("(1) Addition\n");
  printf("(2) Subtraction\n");
  printf("(3) Multiplication\n");
  printf("(4) Division\n");
  printf("(5) Minimum\n");
  printf("(6) Power\n");
  printf("(7) log_a(b)\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("%0.2f", a + b);
      break;
    case 2:
      result = a - b;
      printf("%0.2f", result);
      break;
    case 3:
      result = a*b;
      printf("%0.2f\n", result);
      break;
    case 4:
      if (b != 0) {
        result = a/b;
        printf("%0.2f\n", result);
      }
      else{
        printf("Not divisible by 0\n");
      }
      break;
    case 5:
      if (a > b) {
        printf("%0.2f is the minimum.\n", b);
      }
      else if (a < b) {
        printf("%0.2f is the minimum.\n", a);
      }
      else{
        printf("Both values are equal.\n");
      }
      break;
    case 6:
      result = pow(a, b);
      printf("%0.2f\n", result);
      break;
    case 7:
      if (a>=0 && b>=0) {
        result = log(b) / log(a);
        printf("log %0.2f (%0.2f) = %0.2f\n",a, b, result );
      }
      else{
        printf("Please enter positive numbers\n");
      }
      break;
    default:
      printf("Please input a valid operator next time");
  }

  return 0;
}
