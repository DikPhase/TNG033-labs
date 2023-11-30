/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <format>
#include <cmath>
#include "expression.h"

class Logarithm : public Expression {
    // ADD CODE
public:

    Logarithm(); // Default constructor

    Logarithm(double constant1, double constant2, int base, const Expression& arguemnt); // Constructor with arguments

    ~Logarithm() override; // Default destructor

    void set_base(int newBase);

    bool isRoot(double x) const override;

    operator std::string() const override;

    double operator()(double x) const override;

    Expression* clone() const override;

private:
    double constant1;
    double constant2;
    int base;
    const Expression& argument;
};
