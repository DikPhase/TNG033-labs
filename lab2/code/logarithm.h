/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <cmath>

#include "expression.h"

class Logarithm : public Expression {
    // ADD CODE
public:
    // Constructors
    Logarithm();
    Logarithm(const Expression& exp, double c1, double c2, int b);
    Logarithm(const Logarithm& lgr);

    // Copy constructor
    Expression* clone() const override;

    // Deconstructor
    ~Logarithm();

    // Assign operator
    Logarithm& operator=(const Logarithm& lgr);

    // Override funktioner
    double operator()(double x) const override;

    explicit operator std::string() const override;

    void set_base(int new_base);

private:
    double constant1, constant2;
    int base;
    Expression* expr;
};
