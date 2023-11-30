/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

// ADD implementation of the member functions for class Logarithm
Logarithm::~Logarithm() {
	// Implement if needed
}

Logarithm::Logarithm() : constant1{ 0 }, constant2{ 0 }, base{ 2 }, argument(Polynomial({ 0 })) {} // Default constructor

Logarithm::Logarithm(double c1, double c2, int b, const Expression& arg) // Constructor with arguments
	: constant1(c1), constant2(c2), base(b), argument(arg) {}

void Logarithm::set_base(int newBase) {
	if (newBase > 1) {
		base = newBase;
	}
	else {
		std::cerr << "Invalid base";
	}
}

bool Logarithm::isRoot(double x) const {
	return false;
}

Logarithm::operator std::string() const {
	// Format constants with two digits after the decimal point
	std::string formattedConstants = std::format("{:.2f} + {:.2f}", constant1, constant2);

	// Format the Logarithm expression
	return std::format("{} * Log_{}( {} )", formattedConstants, base, static_cast<std::string>(argument));
}

double Logarithm::operator()(double x) const {
	double d = x;
		return d;
}

Expression* Logarithm::clone() const {
	return new Logarithm(*this);
}