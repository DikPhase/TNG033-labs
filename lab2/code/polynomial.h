/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <cmath>
#include "expression.h"

class Polynomial : public Expression {
    // ADD CODE
public:
    // Constructor to create a polynomial from a vector of doubles
    Polynomial(const std::vector<double>& coefficients);
   
    // Constructor only taking one double
    Polynomial(double constant);
    
    // Destructor
    ~Polynomial() override;

    // Assignment operator
    Polynomial& operator=(const Polynomial& rhs);

    // Add-and-assign operator
    Polynomial& operator+=(const Polynomial& rhs);

    // Add operator with a Polynomial
    Polynomial operator+(const Polynomial& rhs) const;

    // Add operator with a double
    Polynomial operator+(double d) const;

    // Add operator for double and Polynomial
    friend Polynomial operator+(double d, const Polynomial& p);

    // Add and assign operator for double 
    Polynomial& operator+=(double d);

    // Subscript operator
    const double& operator[](std::size_t index) const;

    double& operator[](std::size_t index);

    /* OVERRIDE VIRTUAL FUNCTIONS IN BASE CLASS: START */
    // Check if its a root 
    bool isRoot(double x) const override;

    // Convert a polynomial to a string
    explicit operator std::string() const override;

    // To be able to check root for specific instance
    double operator()(double x) const override;

    Expression* clone() const override;
    /* OVERRIDE VIRTUAL FUNCTOINS IN BASE CLASS: END*/

private:
    std::vector<double> coeffecients;
};