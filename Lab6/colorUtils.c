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

	//One will be Luminosity

	//One will be Lightness
}

int toSepia(int* r, int* g, int* b) {
	//One will be Sepia Red 

	//One will be Sepia Green

	//One will be Sepia Blue
}