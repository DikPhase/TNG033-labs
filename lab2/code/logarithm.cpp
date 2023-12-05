/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

 // ADD implementation of the member functions for class Logarithm
Logarithm::Logarithm() {
	constant1 = 0;
	constant2 = 1;
	base = 2;
	std::vector<double> coeff{ constant1,constant2 };
	expr = new Polynomial{ coeff };
}

Logarithm::Logarithm(const Expression& exp, double c1, double c2, int b) {
	expr = exp.clone();
	constant1 = c1; constant2 = c2;
	base = b;
}

Logarithm::Logarithm(const Logarithm& arg1) {
	constant1 = arg1.constant1; 
	constant2 = arg1.constant2; 
	base = arg1.base;
	expr = arg1.expr->clone();
}

Expression* Logarithm::clone() const {
	return new Logarithm(*this);
}

Logarithm::~Logarithm() {
	delete expr;
	base = 0; constant1 = 0; constant2 = 0;
}

void Logarithm::set_base(int new_base) {
	base = new_base;
}

Logarithm::operator std::string() const {
	std::string os{ "" };
	os += std::format("{:.2f}", constant1);

	if (constant2 < 0) {
		os += std::format(" - {:.2f}", std::abs(constant2));
	}
	else {
		os += std::format(" + {:.2f}", constant2);
	}

	os += std::format(" * Log_{}( {} )", base, std::string(expr -> operator std::string()));

	return os;
}

double Logarithm::operator()(double x) const {
	double result = 0.0;
	double exprSum = expr -> operator()(x);
	result += constant1 + (constant2 * (log(exprSum) / log(base)));
	return result;
}

Logarithm& Logarithm::operator=(const Logarithm& lgr) {
	delete expr;
	base = lgr.base;
	constant1 = lgr.constant1; constant2 = lgr.constant2;
	expr = lgr.expr->clone();
	return *this;
}