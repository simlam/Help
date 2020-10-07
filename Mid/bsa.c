#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main(int argc, char** argv) {

	double height,
		weight,
		weightExp,
		DB,
		hay,
		boyd,
		avg;

	//Initialize variables with command line arguments

	weight = atof(argv[1]);
	height = atof(argv[2]);

	//Error check
	//Condition 1 is command line argument elements since we only have two inputs (weight and height) we have 3 
	//Condition 2 is if the inputs are valid 
	//This program will run only if all checks pass

	if (argc != 3)
	{
		printf("To use: %s weight height\n", argv[0]);
	}
	else if (weight < 0 || height < 0)
	{
		printf("Please enter valid inputs");
	}
	else
	{
		//Split the calculation of ln to seperate variable to not clutter code

		weightExp = (0.6157 - (0.00816474 * log(weight)));

		DB = sqrt((height * weight) / 3600);
		hay = 0.024265 * (pow(height, 0.3964)) * (pow(weight, 0.5378));
		boyd = 0.0333 * pow(height, 0.3) * pow(weight, weightExp);
		avg = (DB + hay + boyd) / 3;

		printf("Patient: \n");
		printf("	Weight: %lf kg\n", weight);
		printf("	Height: %lf cm\n", height);
		printf("--------	--------\n");
		printf("Formula		BSA(m^2)\n");
		printf("Du Bois		%lf\n", DB);
		printf("Haycock		%lf\n", hay);
		printf("Boyd		%lf\n", boyd);
		printf("Average		%lf\n", avg);
	}
	return;
}