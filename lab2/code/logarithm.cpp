/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

 // ADD implementation of the member functions for class Logarithm

// Tom constructor
Logarithm::Logarithm() {
	constant1 = 0;
	constant2 = 1;
	base = 2;
	std::vector<double> coeff{ 0,1 };
	expr = new Polynomial{ coeff };
}

// Constructor med värden
Logarithm::Logarithm(const Expression& exp, double c1, double c2, int b) {
	expr = exp.clone();
	constant1 = c1; constant2 = c2;
	base = b;
}

// Copy constructor
Logarithm::Logarithm(const Logarithm& arg1) {
	constant1 = arg1.constant1; constant2 = arg1.constant2; base = arg1.base;
	expr = arg1.expr->clone();
}

// Clone
Expression* Logarithm::clone() const {
	return new Logarithm(*this);
}

// Deconstructor
Logarithm::~Logarithm() {
	delete expr;
	base = 0; constant1 = 0; constant2 = 0;
}

// Sätter en ny bas
void Logarithm::set_base(int new_base) {
	base = new_base;
}

// Konverterar uttrycket till en string
Logarithm::operator std::string() const {
	std::string os{ "" };
	os += std::format("{:.2f}", constant1);

	if (constant2 < 0) {
		os += std::format(" - {:.2f}", std::abs(constant2));
	}
	else {
		os += std::format(" + {:.2f}", constant2);
	}

	os += std::format(" * Log_{}( {} )", base, static_cast<std::string>(expr -> operator std::string()));

	return os;
}

// Testar ifall resultatet av logaritmen är < epsilon
bool Logarithm::isRoot(double x) const {
	return (std::abs((*this)(x)) < Epsilon);
}

// Räknar ut uttrycket
double Logarithm::operator()(double x) const {
	double result = 0.0;
	double exprSum = expr -> operator()(x);
	result += constant1 + (constant2 * (log(exprSum) / log(base)));
	return result;
}

// Operator =
Logarithm& Logarithm::operator=(const Logarithm& lgr) {
	delete expr;
	base = lgr.base;
	constant1 = lgr.constant1; constant2 = lgr.constant2;
	expr = lgr.expr->clone();
	return *this;
}