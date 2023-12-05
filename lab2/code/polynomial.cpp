/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"

// ADD implementation of the member functions for class Polynomial
Polynomial::Polynomial(const std::vector<double>& coeffs) : coeffecients(coeffs){}
Polynomial::Polynomial(const double constant) : coeffecients(std::vector<double>{constant}) {}
Polynomial::~Polynomial() {
	// implement destructor if needed
}

/* VIRTUAL FUNCTIONS BEGIN */
bool Polynomial::isRoot(double x) const {
	double result = 0.0;
	double xPower = 1.0;

	for (const double& coeff : coeffecients) {
		result += coeff * xPower;
		xPower *= x;
	}
	return std::abs(result) < Epsilon;
}

// Convert polynomial to string
Polynomial::operator std::string() const {
	std::string oss{""};
	for (std::size_t i = 0; i < coeffecients.size(); ++i) {
		if (i > 0)
		{
			if (coeffecients[i] < 0)
			{
				oss += std::format(" - {:.2f}", abs(coeffecients[i]));
				if (i > 0)
				{
					oss += std::format(" * X^{}", i);
				}
			}
			else
			{
				oss += std::format(" + {:.2f}", coeffecients[i]);
				if (i > 0)
				{
					oss += std::format(" * X^{}", i);
				}
			}
		}
		else
		{
			oss += std::format("{:.2f}", coeffecients[i]);
		}
	}
	return oss;
}

// Overloaded operator. It allows us to treat an instance of Polynomial as a function that can be called woth a specific value x
double Polynomial::operator()(double x) const {
	double result = 0.0;
	double xPower = 1.0;
	for (const double& coeff : coeffecients) {
		result += coeff * xPower;
		xPower *= x;
	}
	return result;
}

Expression* Polynomial::clone() const {
	return new Polynomial(*this);
}
/* VIRTUAL FUNCTIONS END*/

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
	Polynomial result = *this;
	result += rhs;
	return result;
}

Polynomial Polynomial::operator+(double d) const {
	Polynomial result = *this;
	result[0] += d;
	return result;
}

Polynomial& Polynomial::operator+=(double d) {
	coeffecients[0] += d;
	return *this;
}

Polynomial operator+(double d, const Polynomial& p) {
	return p + d;
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs) {
		coeffecients = rhs.coeffecients;
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	std::size_t i = 0;
	for (; i < rhs.coeffecients.size(); ++i) {
		
		if (i >= coeffecients.size())
		{
			coeffecients.push_back(rhs.coeffecients[i]);
		}
		else {
			coeffecients[i] += rhs.coeffecients[i];
		}
	}
	
	return *this;
}

/* Subscript operators */
// Not modifiable
const double& Polynomial::operator[](std::size_t index) const {
	if (index < coeffecients.size()) {
		return coeffecients[index];
	}
	else
	{
		static const double zero = 0.0;
		return zero;
	}
}

// Modifiable
double& Polynomial::operator[](std::size_t index) {
	if (index >= coeffecients.size()) {
		throw std::out_of_range("Index is not available");
	}
	else {
		return coeffecients[index];
	}
}

