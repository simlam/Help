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

	if ((*r || *g || *b <= -1) || (*r || *g || *b >= 256))
	{
		return 1;
	}

	if (r || g || b == NULL) {
		return 2;
	}

	//Also no idea if this syntax works but it should if I'm not crazy 
	//Round to get rid of possible errors in the unit test?

	if (mode == 0)
	{
		int avg = (*r + *g + *b) / 3;
		int avg_rd = round(avg);

		r = &avg_rd;
		*g = *r;
		*b = *g;
		return 0;
	}

	else if (mode == 1)
	{
		int maxC = max(*r, *g, *b);
		int minC = min(*r, *g, *b);
		int light = (maxC + minC) / 2;
		int light_rd = round(light);

		r = &light_rd;
		*g = *r;
		*b = *g;
		return 0;
	}

	else if (mode == 2)
	{
		int lum = (0.21 * *r) + (0.72 * *g) + (0.07 * *b);
		int lum_rd = round(lum);

		r = &lum_rd;
		*g = *r;
		*b = *g;
		return 0;
	}

	else {
		return 3;
	}

}

int toSepia(int* r, int* g, int* b) {

	//Value check

	if (r || g || b == NULL) {
		return 4;
	}
	
	if (*r <= -1 || *r >= 256)
	{
		return 5;
	}
	else if (*g <= -1 || *g >= 256)
	{
		return 6;
	}
	else if (*b <= -1 || *b >= 256)
	{
		return 7;
	}
	else {
		//One will be Sepia Red 

		int red = (0.393 * *r) + (0.769 * *g) + (0.189 * *b);
		int red_rd = round(red);

		//One will be Sepia Green

		int green = (0.349 * *r) + (0.686 * *g) + (0.168 * *b);
		int green_rd = round(green);

		//One will be Sepia Blue

		int blue = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);
		int blue_rd = round(blue);

		//I think I need to round somehow to correct errors since we are dealing with intergers
		//Could I round while also adding in the value to the pointer i.e. x = &round(y);
		//Something to test at a later time 
		//It didn't work so added an intermediate variable to hold the rounding calculation

		r = &red_rd;
		g = &green_rd;
		b = &blue_rd;

		return 0;
	}
}