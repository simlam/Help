#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "airDistance.h"

double degreesToRadians(double degree) {

	double radians = degree * 3.14;
	return radians / 180;

}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {

	double sin = sin(originLatitude) * sin(destinationLatitude);
	double cos = cos(originLatitude) * cos(destinationLatitude) * cos(destinationLatitude - originLongitude);
	return acos(sin + cos) * 6371;

}