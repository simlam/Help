/* This is a 401k amortization table */
/*Basic structure is there, however, am I supposed to use an array and does the math check out (p.s. its a no for now)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  double init, contri, avgannualRet, avgmonthlyRet, avgannualInfl, avgmonthlyInfl, adjustedInter, yearsTil, bal, inter, interAccrued, totalNest, month;
  int rows;
  int columns;

  init = atof(argv[1]);
  contri = atof(argv[2]);
  avgannualRet = atof(argv[3]);
  avgannualInfl = atof(argv[4]);
  yearsTil = atof(argv[5]);

  month = yearsTil * 12;
  avgmonthlyRet = avgannualRet / 12;
  avgmonthlyInfl = avgannualInfl /12;
  adjustedInter = ((avgmonthlyRet + 1) / (avgmonthlyInfl + 1)) - 1;

  printf("Month ");
  printf("Interest ");
  printf("Balance ");


  for (rows = 1; rows <= month; rows++) {

    for (columns = 0; columns <= 2; columns++) {

      if (columns == 0) {

        printf("%d ", rows);

      }
      else if (columns == 1) {

        inter = adjustedInter * bal;
        interAccrued += inter;
        printf(" $ %0.2lf ", inter);

      }
      else {

        bal += bal + inter + contri;
        printf(" $ %0.2lf ", bal);

      }

    }

    printf("\n");

  }

  printf("Total Interest Earned: $ %lf\n", interAccrued);
  printf("Total Nest Egg: $ %0.2lf\n", bal);

  return 0;
}
