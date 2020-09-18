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
	double time;
	double percentC;
	double degrees;

	double result;
	double expectedResult;
	double numPassed = 0;
	double numFailed = 0;

//This is the test for degrees to radians
	degrees = 50;
	expectedResult = 0.8722;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
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

	degrees = 60;
	expectedResult = 1.0467;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
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

	degrees = 70;
	expectedResult = 1.2211;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
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

	//This is a test for time dilation

	time = 60;
	percentC = 0.25;
	expectedResult = 69.2820;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	time = 90;
	percentC = 0.50;
	expectedResult = 127.2792;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	time = 120;
	percentC = 0.75;
	expectedResult = 240;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	if (result == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", result, expectedResult);
		numFailed++;
	}

	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

	return 0;

}