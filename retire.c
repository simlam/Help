/* This is a 401k amortization table */
/*Basic structure is there, however, am I supposed to use an array and does the math check out (p.s. its a no for now)*/
/*The program now works but I have not factored in a rounding error, therefore values compared to the expected output on the worksheet is slightly off*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  double bal, contri, avgannualRet, avgmonthlyRet, avgannualInfl, avgmonthlyInfl, adjustedInter, yearsTil, inter, interAccrued, totalNest, month;
  int rows;
  int columns;

  bal = atof(argv[1]);
  contri = atof(argv[2]);
  avgannualRet = atof(argv[3]);
  avgannualInfl = atof(argv[4]);
  yearsTil = atof(argv[5]);

  month = yearsTil * 12;
  avgmonthlyRet = avgannualRet / 12;
  avgmonthlyInfl = avgannualInfl / 12;
  adjustedInter = (1 + avgmonthlyRet) / (1 + avgmonthlyInfl) - 1;

  printf("Month ");
  printf("Interest ");
  printf("Balance \n");


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

        bal += inter + contri;
        printf(" $ %0.2lf ", bal);

      }

    }

    printf("\n");

  }

  printf("Total Interest Earned: $ %0.2lf\n", interAccrued);
  printf("Total Nest Egg: $ %0.2lf\n", bal);

  return 0;
}