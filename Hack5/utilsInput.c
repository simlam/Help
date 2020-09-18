#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

int main(int argc, char** argv) {

	double originLatitude;
	double originLongitude;
	double destinationLatitude;
	double destinationLongitude;
	double originLatitudeRad;
	double originLongitudeRad;
	double destinationLatitudeRad;
	double destinationLongitudeRad;
	double time;
	double percentC;
	double airDistance;
	double timeDilation;

	if (argc < 7 || argc > 7)
	{
		printf("To use utilsInput input origin latitude, origin longitude, destination latitude, destination longitude, time, percent of the speed of light\n");
		exit(1);
	}

	originLatitude = atof(argv[1]);
	originLongitude = atof(argv[2]);
	destinationLatitude = atof(argv[3]);
	destinationLongitude = atof(argv[4]);
	time = atof(argv[5]);
	percentC = atof(argv[6]);

	if (originLatitude <= -91 || originLatitude >= 91)
	{
		printf("Bad Input\n");
		exit(1);
	}
	if (destinationLatitude <= -91 || destinationLatitude >= 91)
	{
		printf("Bad Input\n");
		exit(1);
	}
	if (originLongitude <= -181 || originLongitude >= 181)
	{
		printf("Bad Input\n");
		exit(1);
	}
	if (destinationLongitude <= -181 || destinationLongitude >= 181)
	{
		printf("Bad Input\n");
		exit(1);
	}
	if (time < 0)
	{
		printf("Bad Input\n");
		exit(1);
	}
	if (percentC < 0 || percentC > 1)
	{
		printf("Bad Input\n");
		exit(1);
	}

	originLatitudeRad = degreesToRadians(originLatitude);
	originLongitudeRad = degreesToRadians(originLongitude);
	destinationLatitudeRad = degreesToRadians(destinationLatitude);
	destinationLongitudeRad = degreesToRadians(destinationLongitude);

	airDistance = getAirDistance(originLatitudeRad, originLongitudeRad, destinationLatitudeRad, destinationLongitudeRad);
	timeDilation = lorentzTimeDilation(time, percentC);

	printf("The air distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.4lf\n", originLatitude, originLongitude, destinationLatitude, destinationLongitude, airDistance);
	printf("The time dilation within %.2lf secods at %.2lf the speed of light is %.4lf\n", time, percentC, timeDilation);
}