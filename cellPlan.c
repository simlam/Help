/* Hack 3.0 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

double gbLim, dayCur, usedCur, dailyAvg, gbLeft, gbleftAvg, usedAvg, dayLeft, exceed, remainder;
//Base prompts

  printf("Number of GB in the plan per 30 day period: ");
  scanf("%lf", &gbLim);
  printf("Current day in the 30 day period: ");
  scanf("%lf", &dayCur);
  printf("Total number of GB used so far: ");
  scanf("%lf", &usedCur);

//Calculations

  if (gbLim < 0) {
    printf("Please enter a valid GB limit.");
    return 0;
  }

  if (dayCur<=30 && dayCur>=1) {
    dayLeft = 30 - dayCur;
  }
  else {
    printf("Please enter a valid day within the period between 1 and 30 days");
    return 0;
  }

  if (usedCur >= 0) {                         /*Nested if statements IDK if learned yet but used here*/
    if (usedCur <= gbLim) {
      gbLeft = gbLim - usedCur;
    }
    else if (usedCur > gbLim) {
      printf("You have exceeded your data limt for this period.");
      return 0;
    }
  }
  else {
    printf("Please enter a valid amount of GB used.");
    return 0;
  }


  usedAvg = usedCur / dayCur;
  dailyAvg = gbLim / 30;
  gbleftAvg = gbLeft / dayLeft;
  exceed = (usedAvg * 30) - gbLim;
  remainder = gbLim - (usedAvg * 30);

//Outputs

  printf("%.lf days used, %.lf days remaining\n", dayCur, dayLeft);
  printf("Average daily use: %0.2lf GB/day\n", usedAvg);

//Status check for certain outputs

    if (usedAvg > dailyAvg) {
      printf("You are EXCEEDING your average daily use (%0.2lf GB/day).\n", dailyAvg);
      printf("If you continue this high usage, you'll exceed your data plan by %0.2lf GB\n", exceed);
    }
    else if (usedAvg < dailyAvg) {
      printf("You are BELOW your average daily use (%0.2lf GB/day).\n", dailyAvg);
      printf("If you continue this usage, you'll have %0.2lf GB remaining.\n", remainder);
    }
    else {
      printf("You are AT your average daily use (%0.2lf GB/day).\n", dailyAvg);
    }

  if (dayCur<30) {
    printf("To stay below your data plan, use no more than %0.2lf GB/day.\n", gbleftAvg);
  }
  else {
    printf("You have reached the end of your 30 day period.\n");
  }

  return 0;
}
