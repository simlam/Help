#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//This is a function that will convert rgb to cmyk

int rgbToCMYK(int r, int g, int b, double* c, double* m, double* y, double* k);

double maxC(double a, double b, double c);

int cmykToRGB(double c, double m, double y, double k, int* r, int* g, int* b);