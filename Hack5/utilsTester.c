//This is the unit test for airDistance with libraries
//To fix rounding errors rounded to the nearest 10000 by multiplying the result by 10000, rounding, and then dividing back by 10000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

int main(int argc, char** argv) {

	double originLatitude;
	double originLongitude;
	double destinationLatitude;
	double destinationLongitude;
	double testCase;

	double result;
	double expectedResult;
	double numPassed = 0;
	double numFailed = 0;
//This part is not needed for now
/*
	if (originLatitude <= -181 && originLatitude >= 181)
	{
		printf("Bad Input");
		exit(1);
	}
	if (destinationLatitude <= -181 && destinationLatitude >= 181)
	{
		printf("Bad Input");
		exit(1);
	}
	if (originLongitude <= -91 && originLongitude >= 91)
	{
		printf("Bad Input");
		exit(1);
	}
	if (destinationLongitude <= -91 && destinationLongitude >= 91)
	{
		printf("Bad Input");
		exit(1);
	}
*/

//This is the test for degrees to radians
	testCase = 50;
	expectedResult = 0.8722;
	printf("TESTING: degreesToRadians(%lf)\n", testCase);
	result = degreesToRadians(testCase);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	testCase = 60;
	expectedResult = 1.0467;
	printf("TESTING: degreesToRadians(%lf)\n", testCase);
	result = degreesToRadians(testCase);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	testCase = 70;
	expectedResult = 1.2211;
	printf("TESTING: degreesToRadians(%lf)\n", testCase);
	result = degreesToRadians(testCase);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

//This is a test for air distance

	originLatitude = degreesToRadians(50);
	originLongitude = degreesToRadians(50);
	destinationLatitude = degreesToRadians(90);
	destinationLongitude = degreesToRadians(100);
	expectedResult = 4447.4957;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	originLatitude = degreesToRadians(50);
	originLongitude = degreesToRadians(50);
	destinationLatitude = degreesToRadians(50);
	destinationLongitude = degreesToRadians(50);
	expectedResult = 0.00;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	originLatitude = degreesToRadians(0);
	originLongitude = degreesToRadians(0);
	destinationLatitude = degreesToRadians(50);
	destinationLongitude = degreesToRadians(50);
	expectedResult = 7290.6853;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

	return 0;

}