#include <stdlib.h>
#include <math.h>


#ifndef MODE_H
#define MODE_H

typedef enum {
	AVERAGE,
	LIGHTNESS,
	LUMINOSITY
} Mode;

#endif // !MODE_H


#include "colorUtils.h"

int max(int a, int b, int c) {
	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int min(int a, int b, int c) {
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int* r, int* g, int* b, Mode mode) {
	//Actually don't know if this is the way it's supposed to be 

	int rd;
	int gn;
	int bl;
	
	r = &rd;
	g = &gn;
	b = &bl;

	//One will be Average

	int avg = (rd + gn + bl) / 3;

	//One will be Lightness

	int max = rd > gn ? rd : gn;
	max = max > bl ? max : bl;
	int min = rd > gn ? gn : rd;
	min = min > bl ? bl : min;
	int light = (max + min) / 2;

	//One will be Luminosity

	int lum = (0.21 * rd) + (0.72 * gn) + (0.07 * bl);

	if (mode == 0)
	{
		r = g = b = &avg;
		return 0;
	}

	else if (mode == 1)
	{
		r = g = b = &light;
		return 0;
	}

	else if (mode == 2)
	{
		r = g = b = &lum;
		return 0;
	}

	else {
		exit(1);
	}

}

int toSepia(int* r, int* g, int* b) {

	int rd;
	int gn;
	int bl;

	r = &rd;
	g = &gn;
	b = &bl;

	//One will be Sepia Red 

	int red = (0.393 * rd) + (0.769 * gn) + (0.189 * bl);

	//One will be Sepia Green

	int green = (0.272 * rd) + (0.534 * gn) + (0.131 * bl);

	//One will be Sepia Blue

	int blue = (0.349 * rd) + (0.686 * gn) + (0.168 * bl);

	r = &red;
	g = &green;
	b = &blue;

	return 0;

}