#include "math_stat.h"
#include <cmath>
#include <math.h>
#include <cstdlib>

double integrate(double a, double b, int N) // Simpson's Method for integration (coming soon)
{
	double h = (b-a)/ N;

	return 1.0;
}
double N(double x)  // cumulative distribution function. NOTE: this uses the error function, which closely resembles the CDF and can be interchanged
{
	return 0.5*(1 + erfc(x * M_SQRT1_2) ); // refer to error function and CDF on wikipedia to follow my logic behind this function I created
}


