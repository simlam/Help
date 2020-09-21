//This is the function prototyping 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

#define M_PI 3.14159265358979323846

//To make sure values can equate rounded to the nearest 10000

double degreesToRadians(double degree) {

	double radians = degree / 180;
	double convert =  radians * M_PI;
	return convert;

}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {
	double radorilat = degreesToRadians(originLatitude);
	double radorilon = degreesToRadians(originLongitude);
	double raddeslat = degreesToRadians(destinationLatitude);
	double raddeslon = degreesToRadians(destinationLongitude);
	double sinlat = sin(radorilat) * sin(raddeslat);
	double coslat = cos(radorilat) * cos(raddeslat) * cos(raddeslon - radorilon);
	double distance = acos(sinlat + coslat) * 6371;
	return distance;
}

//This function is one that I don't know how to go about 

//Assume "t" or time is in seconds and that "v^2 / c^2" is a significant percentage of the speed of light between 0 and 1

double lorentzTimeDilation(double time, double percentC) {

	double denom = 1 - (percentC * percentC);
	double TimeDil = time / sqrt(denom);
	return TimeDil;
}