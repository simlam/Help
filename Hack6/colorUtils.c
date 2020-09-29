#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"


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

	int rd = (r / 255) * 100;
	int rp = round(rd) / 100;
	int gd = (g / 255) * 100;
	int gp = round(gd) / 100;
	int bd = (b / 255) * 100;
	int bp = round(bd) / 100;

	double kd = (1 - max(rp, gp, bp)) * 100;
	double kr = round(kd) / 100;
	double cd = ((1 - rp - kr) / (1 - kr)) * 100;
	double cr = round(cd) / 100;
	double md = ((1 - gp - kr) / (1 - kr)) * 100;
	double mr = round(md) / 100;
	double yd = ((1 - bp - kr) / (1 - kr)) * 100;
	double yr = round(yd) / 100;

	k = &kr;
	c = &cr;
	m = &mr;
	y = &yr;

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

	int rr = round(255 * (1 - c) * (1 - k));
	int gr = round(255 * (1 - m) * (1 - k));
	int br = round(255 * (1 - y) * (1 - k));

	if (rr > 255)
	{
		rr = 255;
	}

	if (gr > 255)
	{
		gr = 255;
	}

	if (br > 255)
	{
		br = 255;
	}

	r = &rr;
	g = &gr;
	b = &br;

}