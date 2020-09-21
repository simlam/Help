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
	double result_rounding;
	double final;

	double result;
	double expectedResult;
	double numPassed = 0;
	double numFailed = 0;

//This is the test for degrees to radians
	degrees = 50;
	expectedResult = 0.872665;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	degrees = 60;
	expectedResult = 1.047198;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	degrees = 70;
	expectedResult = 1.221730;
	printf("TESTING: degreesToRadians(%lf)\n", degrees);
	result = degreesToRadians(degrees);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: degreesToRadians returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

//This is a test for air distance

	originLatitude = 50;
	originLongitude = 50;
	destinationLatitude = 90;
	destinationLongitude = 100;
	expectedResult = 4447.797066;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	originLatitude = 50;
	originLongitude = 50;
	destinationLatitude = 50;
	destinationLongitude = 50;
	expectedResult = 0.00;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	originLatitude = 0;
	originLongitude = 0;
	destinationLatitude = 50;
	destinationLongitude = 50;
	expectedResult = 7293.887107;
	printf("TESTING: getAirDistance(%lf, %lf, %lf, %lf)\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: getAirDistance returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	//This is a test for time dilation

	time = 60;
	percentC = 0.25;
	expectedResult = 61.967734;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	time = 90;
	percentC = 0.50;
	expectedResult = 103.923048;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	time = 120;
	percentC = 0.75;
	expectedResult = 181.422947;
	printf("TESTING: lorentzTimeDilation(%lf, %lf)\n", time, percentC);
	result = lorentzTimeDilation(time, percentC);
	result_rounding = result * 1000000;
	final = round(result_rounding) / 1000000;
	if (final == expectedResult)
	{
		printf("PASSED\n");
		numPassed++;
	}
	else
	{
		printf("FAILED: lorentzTimeDilation returned %lf, expected %lf\n", final, expectedResult);
		numFailed++;
	}

	printf("Number Of Test Cases Passed: %.2lf \n", numPassed);
	printf("Number Of Test Cases Failed: %.2lf \n", numFailed);
	printf("Percent Passed:				 %.2lf \n", 100 * numPassed / (numFailed + numPassed));

	return 0;

}