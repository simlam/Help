#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "rgb.h"


int max(int a, int b, int c) {

	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);

}

int rgbtoCMYK(int r, int g, int b, double* c, double* m, double* y, double* k) {

	if ((r || g || b <= -1) || (r || g || b >= 256))
	{
		return 1;
	}

	if (!c || !m || !y || !k)
	{
		return 1;
	}

	if (r && g && b == 0)
	{
		double cr = 0;
		double mr = 0;
		double yr = 0;
		double kr = 1;

		c = &cr;
		m = &mr;
		y = &yr;
		k = &kr;

		return 0;
	}

	int rp = (r / 255);
	int gp = (g / 255);
	int bp = (b / 255);

	double kr = 1 - max(rp, gp, bp);
	double cr = (1 - rp - kr) / (1 - kr);
	double mr = (1 - gp - kr) / (1 - kr);
	double yr = (1 - bp - kr) / (1 - kr);

	k = &kr;
	c = &cr;
	m = &mr;
	y = &yr;

	return 0;
}

int cmyktoRGB(double c, double m, double y, double k, int* r, int* g, int* b) {

	if ((c || m || y || k <= -1) || (c || m || y || k >= 2))
	{
		return 1;
	}

	if (!r || !g || !b)
	{
		return 1;
	}

	int rr = 255 * (1 - c) * (1 - k);
	int gr = 255 * (1 - m) * (1 - k);
	int br = 255 * (1 - y) * (1 - k);

	r = &rr;
	g = &gr;
	b = &br;

	return 0;
}