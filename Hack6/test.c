#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"


int main() {

	int r,
		g,
		b;
	double c,
		m,
		y,
		k;


/*
	printf("Please enter R: ");
	scanf("%d", &r);
	printf("Please ener G: ");
	scanf("%d", &g);
	printf("Please enter B: ");
	scanf("%d", &b);

	rgbtoCMYK(r, g, b, &c, &m, &y, &k);

	printf("R: %d, G: %d, B: %d\n", r, g, b);
	printf("C: %.2lf, M: %.2lf, Y: %.2lf, K: %.2lf\n", c, m, y, k);
*/


	printf("Please enter C: ");
	scanf("%lf", &c);
	printf("Please ener M: ");
	scanf("%lf", &m);
	printf("Please enter Y: ");
	scanf("%lf", &y);
	printf("Please enter K: ");
	scanf("%lf", &k);

	cmyktoRGB(c, m, y, k, &r, &g, &b);

	printf("R: %d, G: %d, B: %d\n", r, g, b);
	printf("C: %.2lf, M: %.2lf, Y: %.2lf, K: %.2lf\n", c, m, y, k);

	return 0;

}

