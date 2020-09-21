#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int min(int a, int b, int c) {
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int* r, int* g, int* b, Mode mode) {
	//Actually don't know if this is the way it's supposed to be
	//When using a pointer variable in code always remember the * before the variable name unless declaring a reference

	//Value check

	if (*r, *g, *b < 0 || *r, *g, *b > 255)
	{
		exit(1);
	}
	
	//One will be Average

	int avg = (*r + *g + *b) / 3;

	//One will be Lightness

	int maxC = max(*r, *g, *b);
	int minC = min(*r, *g, *b);
	int light = (maxC + minC) / 2;

	//One will be Luminosity

	int lum = (0.21 * *r) + (0.72 * *g) + (0.07 * *b);

	if (mode == AVERAGE)
	{
		r = g = b = &avg;
		return 0;
	}

	else if (mode == LIGHTNESS)
	{
		r = g = b = &light;
		return 0;
	}

	else if (mode == LUMINOSITY)
	{
		r = g = b = &lum;
		return 0;
	}

	else {
		exit(1);
	}

}

int toSepia(int* r, int* g, int* b) {

	//Value check

	if (*r, *g, *b < 0 || *r, *g, *b > 255)
	{
		exit(1);
	}

	//One will be Sepia Red 

	int red = (0.393 * *r) + (0.769 * *g) + (0.189 * *b);

	//One will be Sepia Green

	int green = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);

	//One will be Sepia Blue

	int blue = (0.349 * *r) + (0.686 * *g) + (0.168 * *b);

	r = &red;
	g = &green;
	b = &blue;

	return 0;

}