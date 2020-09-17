//This is the function prototyping 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

//To make sure values can equate rounded to the nearest 10000

double degreesToRadians(double degree) {

	double radians = degree / 180;
	double convert =  radians * 3.14;
	double radians_round = convert * 10000;
	return round(radians_round) / 10000;

}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {

	double sinlat = sin(originLatitude) * sin(destinationLatitude);
	double coslat = cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude - originLongitude);
	double distance = acos(sinlat + coslat) * 6371;
	double distance_round = distance * 10000;
	return round(distance_round) / 10000;

}

//This function is one that I don't know how to go about 

double lorentzTimeDilation(double time, double percentC) {

	double denom = 1 - percentC;
	return 1 / sqrt(denom);

}