/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>

#include "expression.h"

class Logarithm : public Expression {
    // ADD CODE
public:

    bool isRoot(double x) const override;

    explicit operator std::string() const override;

    double operator()(double x) const override;

    Expression* clone() const override;
};
