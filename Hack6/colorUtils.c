#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"


double maxC(double a, double b, double c) {

	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);

}

int rgbtoCMYK(int r, int g, int b, double* c, double* m, double* y, double* k) {

	if (r < 0 || g < 0 || b < 0)
	{
		return 1;
	}
	if (r > 255 || g > 255 || b > 255)
	{
		return 1;
	}
	if (!c || !m || !y || !k)
	{
		return 1;
	}
	if (r == 0 && g == 0 && b == 0)
	{
		 *c = 0.0;
		 *m = 0.0; 
		 *y = 0.0;
		 *k = 1.0;
		 return 0;
	
	}

	double rp = (double)r / 255;
	double gp = (double)g / 255;	
	double bp = (double)b / 255;
		

	double kd = (1 - (maxC(rp, gp, bp))) * 100;
	double kp = round(kd) / 100;
	double cd = ((1 - rp - kp) / (1 - kp)) * 100;
	double cp = round(cd) / 100;
	double md = ((1 - gp - kp) / (1 - kp)) * 100;
	double mp = round(md) / 100;
	double yd = ((1 - bp - kp) / (1 - kp)) * 100;
	double yp = round(yd) / 100;

	*k = kp;
	*c = cp;
	*m = mp;
	*y = yp;

	return 0;
	
}

int cmyktoRGB(double c, double m, double y, double k, int* r, int* g, int* b) {

	if (c < -1 || m < -1 || y < -1 || k < -1)
	{
		return 1;
	}
	if (c > 2 || m > 2 || y > 2 || k > 2)
	{
		return 1;
	}
	if (!r || !g || !b)
	{
		return 1;
	}



		double rd = 255 * (1 - c) * (1 - k);
		int rr = (int)round(rd);
		double gd = 255 * (1 - m) * (1 - k);
		int gr = (int)round(gd);
		double bd = 255 * (1 - y) * (1 - k);
		int br = (int)round(bd);

		*r = rr;
		*g = gr;
		*b = br;


		if (rr > 255)
		{
			*r = 255;
		}

		if (gr > 255)
		{
			*g = 255;
		}

		if (br > 255)
		{
			*b = 255;
		}
		return 0;
	
}