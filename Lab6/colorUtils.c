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
	//One will be Average

	if (Mode = 0)
	{
		int avg = (r + g + b) / 3;
		return avg;
	}

	//One will be Lightness

	else if (Mode = 1)
	{
		int max = r > g ? r : g;
		max = max > b ? max : b;
		int min = r > g ? g : r;
		min = min > b ? b : min;
		int light = (max + min) / 2;
		return light;
	}

	//One will be Luminosity

	else if (Mode = 2)
	{
		int lum = (0.21 * r) + (0.72 * g) + (0.07 * b);
		return lum;
	}

	else {
		exit(1);
	}

}

int toSepia(int* r, int* g, int* b) {
	//One will be Sepia Red 

	return (0.393 * r) + (0.769 * g) + (0.189 * b);

	//One will be Sepia Green

	return (0.272 * r) + (0.534 * g) + (0.131 * b);

	//One will be Sepia Blue

	return (0.349 * r) + (0.686 * g) + (0.168 * b);

}