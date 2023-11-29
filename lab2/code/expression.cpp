/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}

/* ************************* */

bool Expression::isRoot(double x) const {
    return std::abs((*this)(x)) < Epsilon;
}

std::ostream& operator<<(std::ostream& os, const Expression & expr) {
    os << static_cast<std::string>(expr);
    return os;
}