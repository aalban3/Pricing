#include "option_pricing.h"
#include "math_stat.h"
#include <cmath>
#include <math.h>
#include <cstdlib>


void PriceOption::init()
{
	K	  = 10.0;
	r	  = 0.05;
	T	  = 1.0;
	D     = 0.0;	// for my basic (vanilla) option there is no dividend
	S	  = 10.0;  // when a spot = strike price this is called being "at the money"
	sigma = 0.1;
}

void PriceOption::copy(const PriceOption& vop)
{
	K     = vop.getK();
	r	  = vop.getr();
	T	  = vop.getT();
	S	  = vop.getS();
	sigma = vop.getsigma();
}

PriceOption::PriceOption(){init();}


PriceOption::PriceOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma, const double& _D)
{
	K = _K;
	r = _r;
	T = _T;
	D = _D;
	S = _S;
	sigma = _sigma;
}

PriceOption::PriceOption(const PriceOption& vop)
{
	copy(vop);
}

PriceOption& PriceOption::operator=(const PriceOption& vop)
{
	if (this == &vop)
		return *this;
	copy(vop);
	return *this;
}

double PriceOption::getK() const
{
	return K;
}
double PriceOption::getr() const
{
	return r;
}
double PriceOption::getT() const
{
	return T;
}
double PriceOption::getS() const
{
	return S;
}
double PriceOption::getsigma() const
{
	return sigma;
}

double PriceOption::calc_call_price() const
{
	double  d1 = ( log(S/K) + sigma * sigma * 0.5 * T ) / (sigma* sqrt(T));
	double  d2 = d1 - (sigma*sqrt(T));

	return S*exp(-D*T)*N(d1) - K*exp(-r*T)*N(d2);  // this formula assumes dividend is equal to zero, you may add dividend to the constructor if you want to or need to apply it
}

double PriceOption::calc_put_price() const
{
	double  d1 = ( log(S/K) + sigma * sigma * 0.5 * T ) / (sigma* sqrt(T));
	double  d2 = d1 - (sigma*sqrt(T));

	return K*exp(-r*T)*N(-d2) - S*exp(-D*T)*N(-d1);
}
