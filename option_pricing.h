#ifndef _OPTION_PRICING_H_
#define _OPTION_PRICING_H_

// Black-Scholes formula reference
// C = S*N(d1) - K*d^(-rT)*N(d2)   no dividend

class PriceOption
{
public:
	  PriceOption();                                     // Default constructor - has no parameters
	  PriceOption(const double& _K, const double& _r, const double& _T,  const double& _S, const double& _sigma, const double& _D);  // Parameter constructor
	  PriceOption(const PriceOption& vop);             // Copy constructor
	  PriceOption& operator=(const PriceOption& vop);  // Assignment operator -- Overloading operator
	  virtual ~PriceOption();                            // virtual destructor
	  double getK() const;
	  double getr() const;
	  double getT() const;
	  double getS() const;
	  double getsigma() const;

	  double calc_call_price() const;    // calculate call option
	  double calc_put_price() const;	 // calculate put option

private:
	  void init();
	  void copy(const PriceOption& vop);

	  // Black-Scholes formula reference
	  // C = S*e^(-dT)*N(d1) - K*e^(-rT)*N(d2)

	  double K;       // Strike price
	  double r;       // Risk-free interest rate
	  double T;       // Option maturity time, one year in this case
	  double D;		  // dividend yield,
	  double S;       // Stock price
	  double sigma;   // Stock volatility


};



#endif
