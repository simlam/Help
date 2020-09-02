
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  double agi;
  char c;
  double tax;
  double childCredit;
  double totalTax;
  int numChildren;

  printf("Please enter your adjusted gross income (AGI): ");
  scanf("%lf", &agi);
  //remove the "enter" endline character
  getchar();

  printf("Do you have any children? (Y) or (N)? ");
  c = getchar();

  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? ");
    scanf("%d", &numChildren);
  }
//tax bracket calculations
    if (agi>0 && agi<=17000) {
      tax = agi * 0.1;
    }
    else if (agi>17000 && agi<=69000) {
      tax = 1700 + 0.15 * (agi - 17000);
    }
    else if (agi>69000 && agi<=139350) {
      tax = 9500 + 0.25 * (agi - 69000);
    }
    else if (agi>139350 && agi<=212300) {
      tax = 27087.50 + .28 * (agi - 139350);
    }
    else if (agi>212300 && agi<=379150) {
      tax = 47513.50 + 0.33 * (agi - 212300);
    }
    else if (agi>379150) {
      tax = 102574 + 0.35 * (agi - 379150);
    }
    else{
      printf("Please enter a valid amount.\n");
    }
//child credit calculations
    if (c == 'y' || c == 'Y') {
      childCredit = numChildren * 1000;
    }
//total tax calculations
  totalTax = tax - childCredit;

  if (totalTax <= 0) {
    totalTax = 0;
  }

  //TODO: compute the tax, child credit, and total tax here

  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);

  return 0;
}
