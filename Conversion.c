#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  double USD;
  double BPD;
  double JPD;
  double SD;

  printf("Please input the total amount of US Dollars: ");
  scanf("%lf\n", &USD);

  SD = USD * 0.9;
  BPD = 0.6 * SD;
  JPD = 76.8 * SD;

  printf("You get %lf British Pounds and %lf Japanese JPY.\n", BPD, JPD );
  return 0;
}
