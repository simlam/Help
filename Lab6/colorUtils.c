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
	//Pointer to store the results of all calculations and pass through

	int* result;
	
	//One will be Average

	int avg = (r + g + b) / 3;

	//One will be Lightness

	int max = r > g ? r : g;
	max = max > b ? max : b;
	int min = r > g ? g : r;
	min = min > b ? b : min;
	int light = (max + min) / 2;

	//One will be Luminosity

	int lum = (0.21 * r) + (0.72 * g) + (0.07 * b);

	if (Mode = 0)
	{
		result = &avg;
		return result;
	}

	else if (Mode = 1)
	{
		result = &light;
		return result;
	}

	else if (Mode = 2)
	{
		result = &lum;
		return result;
	}

	else {
		exit(1);
	}

}

int toSepia(int* r, int* g, int* b) {
	
	//Pointer to hold results 

	int* results;

	//One will be Sepia Red 

	int red = (0.393 * r) + (0.769 * g) + (0.189 * b);

	//One will be Sepia Green

	int green = (0.272 * r) + (0.534 * g) + (0.131 * b);

	//One will be Sepia Blue

	int blue = (0.349 * r) + (0.686 * g) + (0.168 * b);

}