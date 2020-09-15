/* This is a 401k amortization table */
/*Basic structure is there, however, am I supposed to use an array and does the math check out (p.s. its a no for now)*/
/*The program now works but I have not factored in a rounding error, therefore values compared to the expected output on the worksheet is slightly off*/
/*One way to round to nearest cent is to convert dollar amount to cents and do calculations as cents and convert to dollar amounts afterwards*/
/*Another way to get around to rounding to nearest cent is to

double bal_rounded = floor(bal * 100 + 0.5) / 100;

and repeat for each calculation
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  double bal, contri, avgannualRet, avgmonthlyRet, avgannualInfl, avgmonthlyInfl, adjustedInter, yearsTil, inter, interAccrued, month, bal_rounded, inter_rounded,adjustedInter_rounded;
  double monthlyadjustedInter;
  int rows;
  int columns;

  bal = atof(argv[1]);
  contri = atof(argv[2]);
  avgannualRet = atof(argv[3]);
  avgannualInfl = atof(argv[4]);
  yearsTil = atof(argv[5]);

  month = yearsTil * 12;
  /*avgmonthlyRet = ((avgannualRet / 12) * 100 + 0.5) / 100;
  avgmonthlyInfl = ((avgannualInfl / 12) * 100 + 0.5) / 100;
  adjustedInter = (1 + avgmonthlyRet) / (1 + avgmonthlyInfl) - 1;
  adjustedInter_rounded = (adjustedInter * 100 + 0.5) / 100.;*/
  adjustedInter = (1 + avgannualRet)/(1 + avgannualInfl) - 1;
  monthlyadjustedInter = adjustedInter/12;



  printf(" Month ");
  printf(" Interest ");
  printf(" Balance \n");


  for (rows = 1; rows <= month; rows++) {

    for (columns = 0; columns <= 2; columns++) {

      if (columns == 0) {

        printf(" %d ", rows);

      }
      else if (columns == 1) {

        inter = monthlyadjustedInter * bal;
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

  printf(" Total Interest Earned: $ %0.2lf\n", interAccrued);
  printf(" Total Nest Egg: $ %0.2lf\n", bal);

  return 0;
}
