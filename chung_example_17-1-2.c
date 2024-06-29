/*
 * Chung book Example 17.1.2
 * CopyRight: Bardal‫®‬
 * 25.september.2020
 */

#include <stdio.h>
#define sqrt2 (1.414213562)

double x[] = {-4, -3, -2, - sqrt2, 0, 0, 0, - 2 * sqrt2, -2.121320344};
double y[] = {0, 0, 0, sqrt2, 2, 3, 4, 2 * sqrt2, 2.121320344};

double p1 (double xi, double eta)
{
	return 4 * (xi - 0.5) * (xi - 1) * (eta - 0.5) * (eta - 1);
}

double p2 (double xi, double eta)
{
	return -8 * (xi) * (xi - 1) * (eta - 0.5) * (eta - 1);
}
double p3 (double xi, double eta)
{
	return 4 * (xi) * (xi - 0.5) * (eta - 0.5) * (eta - 1);
}
double p4 (double xi, double eta)
{
	return -8 * (xi) * (xi - 0.5) * (eta) * (eta - 1);
}
double p5 (double xi, double eta)
{
	return 4 * (xi) * (xi - 0.5) * (eta) * (eta - 0.5);
}
double p6 (double xi, double eta)
{
	return -8 * (xi) * (xi - 1) * (eta) * (eta - 0.5);
}
double p7 (double xi, double eta)
{
	return 4 * (xi - 0.5) * (xi - 1) * (eta) * (eta - 0.5);
}
double p8 (double xi, double eta)
{
	return -8 * (xi - 0.5) * (xi - 1) * (eta) * (eta - 1);
}
double p9 (double xi, double eta)
{
	return 16 * (xi) * (xi - 1) * (eta) * (eta - 1);
}


double l_2d_x (double xi, double eta)
{
	return 
	x[0] * p1(xi, eta) + x[1] * p2(xi, eta) + x[2] * p3(xi, eta) + 
	x[3] * p4(xi, eta) + x[4] * p5(xi, eta) + x[5] * p6(xi, eta) + 
	x[6] * p7(xi, eta) + x[7] * p8(xi, eta) + x[8] * p9(xi, eta);
}
double l_2d_y (double xi, double eta)
{
	return 
	y[0] * p1(xi, eta) + y[1] * p2(xi, eta) + y[2] * p3(xi, eta) + 
	y[3] * p4(xi, eta) + y[4] * p5(xi, eta) + y[5] * p6(xi, eta) + 
	y[6] * p7(xi, eta) + y[7] * p8(xi, eta) + y[8] * p9(xi, eta);
}

int main ()
{
	///double xi[] = {0, .5, 1, 1, 1, .5, 0, 0, .5};
	///double eta[] = {0, 0, 0, .5, 1, 1, 1, .5, .5};
	
	FILE *fp = fopen("mesh.plt", "w");
	for (double i = 0; i <= 1; i += 0.01)
	{
		for (double j = 0; j <= 1; j += 0.01)
		{
			fprintf(fp, "%f %f\n", l_2d_x(i, j), l_2d_y(i, j));
		}
	}
	fclose(fp);
}
