#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "rgb.h"


int main(int argc, char** argv) {

	int a,
		bi,
		ci,
		rr,
		gr,
		br;
	int*
		 r,
		 g,
		 b;
	double cr,
		mr,
		yr,
		kr;
	double*
		c,
		m,
		y,
		k;
	//comparison variables
	double rc,
		gc,
		bc,
		cc,
		mc,
		yc,
		kc;
	double result,
		expectedResult,
		numPassed = 0,
		numFailed = 0;

	//This is a test for max

	a = 10;
	bi = 10;
	ci = 11;
	result = max(a, bi, ci);
	printf("This is a test for Max(%d, %d, %d\n)", a, bi, ci);
	expectedResult = 11;
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: MAX result: %d, expected result: %d\n", result, expectedResult);
		numFailed++;
	}

	a = 5;
	bi = 10;
	ci = 0;
	result = max(a, bi, ci);
	printf("This is a test for Max(%d, %d, %d)\n", a, bi, ci);
	expectedResult = 10;
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: MAX result: %d, expected result: %d\n", result, expectedResult);
		numFailed++;
	}

	a = 1;
	bi = 1;
	ci = 2;
	result = max(a, bi, ci);
	printf("This is a test for Max(%d, %d, %d)\n", a, bi, ci);
	expectedResult = 2;
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: MAX result: %d, expected result: %d\n", result, expectedResult);
		numFailed++;
	}

	//This is a test for rgbtoCMYK

	rr = 0;
	gr = 0;
	br = 0;
	cr = 0;
	mr = 0;
	yr = 0;
	kr = 0;
	result = rgbtoCMYK(rr, gr, br, &cr, &mr, &yr, &kr);
	printf("This is a test for rgbtoCMYK(%d, %d, %d, *c, *m, *y, *k)\n", rr, gr, br);
	expectedResult = 

	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED did not return correct values\n");
		numFailed++;
	}

	rr = 100;
	gr = 100;
	br = 100;
	cr = 0;
	mr = 0;
	yr = 0;
	kr = 0;
	result = rgbtoCMYK(rr, gr, br, &cr, &mr, &yr, &kr);
	printf("This is a test for rgbtoCMYK(%d, &d, %d, *c, *m, *y, *k)\n", rr, gr, br);
	expectedResult = 

	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED did not return correct values\n");
		numFailed++;
	}

	printf("Number Passed: %.2lf\n", numPassed);
	printf("Number Failed: %.2lf\n", numFailed);
	printf("Percent Passed: %.2lf\n", ((numPassed / (numPassed + numFailed)) * 100));
}
