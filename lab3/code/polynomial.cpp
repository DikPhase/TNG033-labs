/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

// Sets key (exponent) to zero and "partners" it with given coefficient 
Polynomial::Polynomial(int coeff) {
	if (coeff != 0) { // Checks if coefficient isnt 0
		coefficients_table[0] = coeff;
	}
}

Polynomial::Polynomial(int coefficient, int exponent) {
	if (coefficient != 0) { // Checks so the coefficient isnt 0
		coefficients_table[exponent] = coefficient; // Adds a term to the 'terms' map. exponent is used as key and coefficient is corresponding value
	}
}

Polynomial::Polynomial(const std::vector<std::pair< int, int>>& termsVector) { // vector of pairs
	std::copy(termsVector.begin(), termsVector.end(), std::inserter(coefficients_table, end(coefficients_table))); // Inserts a copy of a vector pair into the end of the terms map
}

// Loop through all the terms in the vector.
int Polynomial::degree() const {
	int exponentValue = 0;
	for (const auto& term : coefficients_table) { // set a reference to a term and const to not change value
		exponentValue = std::max(exponentValue, term.first); // Get the highest value among the first parameters in the vector (exponents)
	}
	return exponentValue;
}


// 
Polynomial::operator std::string() const {
    std::string result = "";

    for (auto it = coefficients_table.begin(); it != coefficients_table.end(); ++it) {
        int coefficient = it->second;
        int exponent = it->first;

        if (coefficient != 0 || exponent == 0) {
            if (coefficient < 0 && it != coefficients_table.begin()) {
                coefficient = std::abs(coefficient);
                result += std::format(" - {}X^{}", coefficient, exponent);
            }
            else if (coefficient > 0 && it != coefficients_table.begin()) {
                result += std::format(" + {}X^{}", coefficient, exponent);
            }
            else if (coefficient < 0 && it == coefficients_table.begin()) {
                result += std::format("{}X^{}", coefficient, exponent);
            }
            else {
                result += std::format("{}X^{}", coefficient, exponent);
            }
        }
    }
    if (coefficients_table.empty()) {
        result = "0";
    }
	return result;
}


// Adds the terms of the right-hand side polynomial (rhs) to the current polynomial (*this).
// After addition, terms with zero coefficients are removed to maintain a compact representation.
Polynomial Polynomial::operator+=(const Polynomial& rhs) {
    for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] += i.second; // Adds the coefficient of the term from rhs to the corresponding term in the current polynomial (*this).
        if (coefficients_table[i.first] == 0) {
            coefficients_table.erase(i.first); // Only store none-zero terms in map
        }
    }
    return *this;
}

// Same-same as above, but different 
Polynomial Polynomial::operator-=(const Polynomial& rhs) {
    for (const auto& i : rhs.coefficients_table) {
        coefficients_table[i.first] -= i.second;
        if (coefficients_table[i.first] == 0) {
            coefficients_table.erase(i.first);
        }
    }
    return *this;
}


// Multiplies the current polynomial by a single term represented by 'activeTerms'.
// Returns a new polynomial representing the result of the multiplication.
Polynomial Polynomial::multiply(std::pair<int, int> activeTerms) {
    Polynomial result; // Initialize a polynomial to store the results
    for (std::pair<int, int> i : this->coefficients_table) { // Iterate through each term in the polynomial
        int exponent = i.first + activeTerms.first;
        int coefficient = i.second * activeTerms.second;
        result.coefficients_table[exponent] = coefficient;
    }
    return result;
}

Polynomial Polynomial::operator*=(const Polynomial& rhs) {
    Polynomial result;  // Initialize a temporary polynomial to store the result
    if (this->coefficients_table.empty() || rhs.coefficients_table.empty()) {
        this->coefficients_table.clear();  // If either of the polynomials is empty, set the current polynomial to zero
        return *this;         // Return the modified polynomial
    }
    Polynomial rhs2 = rhs;  // Create a copy of the right-hand side polynomial
    for (auto i : coefficients_table) {
        result += rhs2.multiply(i);  // Multiply each term of the current polynomial by rhs2 and accumulate the result
    }
    *this = result;  // Update the current polynomial with the final result
    return *this;  // Return the modified polynomial
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    return lhs.coefficients_table == rhs.coefficients_table;
}

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial result = lhs;
    result -= rhs;
    return result;
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial result = lhs;
    result *= rhs;
    return result;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    Polynomial result = lhs;
    result += rhs;
    return result;
}