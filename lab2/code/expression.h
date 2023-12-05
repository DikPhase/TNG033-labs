/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <sstream>
#include <format>

constexpr double Epsilon = 1.0e-5;

class Expression {
public:
    // Destructor 
    virtual ~Expression() { // Decrement the number of existing expressions
        --count_expressions;
    }

    // Pure virtual function, needs to be implemented in derived class
    bool isRoot(double x) const; 

    // Pure virtual function, needs to be implemented in derived class
    virtual explicit operator std::string() const = 0; 

    // Pure virtual function, needs to be implemented in derived class
    virtual double operator()(double x) const = 0;

    // Pure virtual function, needs to be implemented in derived class
    virtual Expression* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Expression& expr); // Overloads the stream insertion operator for printing

    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // total number of existing expressions -- only to help to detect bugs in the code
    static std::size_t count_expressions; // A static mamber variable to keep track of exsisting instances of Expressions

    Expression& operator=(const Expression&) = default;
};
