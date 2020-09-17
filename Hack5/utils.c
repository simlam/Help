#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

double degreesToRadians(double degree) {

	double radians = degree / 180;
	double convert =  radians * 3.14;
	return convert;

}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {

	double sinlat = sin(originLatitude) * sin(destinationLatitude);
	double coslat = cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude - originLongitude);
	double distance = acos(sinlat + coslat) * 6371;
	return distance;

}

double lorentzTimeDilation(double time, double percentC) {

	double denom = 1 - percentC;
	return 1 / sqrt(denom);

}