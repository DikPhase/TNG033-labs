/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

Polynomial::Polynomial() {

}

Polynomial::Polynomial(int coeff) {
	if (coeff != 0) {
		terms[0] = coeff;
	}
}

Polynomial::Polynomial(int coefficient, int exponent) {
	if (coefficient != 0) { // Checks so the coefficient isnt 0
		terms[exponent] = coefficient; // Adds a term to the 'terms' map. exponent is used as key and coefficient is corresponding value
	}
}

Polynomial::Polynomial(const std::vector<std::pair< int, int>>& termsVector) { // vector of pairs
	std::copy(termsVector.begin(), termsVector.end(), std::inserter(terms, end(terms)));
}

// Loop through all the terms in the vector.
int Polynomial::degree() const {
	int exponentValue = 0;
	for (const auto& term : terms) { // set a reference to a term and const to not change value
		exponentValue = std::max(exponentValue, term.first); // Get the highest value among the second parameters in the vector (exponents)
	}
	return exponentValue;
}


// 
Polynomial::operator std::string() const {
    std::string result = "";

    for (auto it = terms.begin(); it != terms.end(); ++it) {
        int coefficient = it->second;
        int exponent = it->first;

        if (coefficient != 0 || exponent == 0) {
            if (coefficient < 0 && it != terms.begin()) {
                coefficient = std::abs(coefficient);
                result += std::format(" - {}X^{}", coefficient, exponent);
            }
            else if (coefficient > 0 && it != terms.begin()) {
                result += std::format(" + {}X^{}", coefficient, exponent);
            }
            else if (coefficient < 0 && it == terms.begin()) {
                result += std::format("{}X^{}", coefficient, exponent);
            }
            else {
                result += std::format("{}X^{}", coefficient, exponent);
            }
        }
    }
    if (terms.empty()) {
        result = "0";
    }
	return result;
}


// Adds the terms of the right-hand side polynomial (rhs) to the current polynomial (*this).
// After addition, terms with zero coefficients are removed to maintain a compact representation.
Polynomial Polynomial::operator+=(const Polynomial& rhs) {
    for (const auto& i : rhs.terms) {
        terms[i.first] += i.second;
        if (terms[i.first] == 0) {
            terms.erase(i.first);
        }
    }
    return *this;
}

// Same-same as above, but different 
Polynomial Polynomial::operator-=(const Polynomial& rhs) {
    for (const auto& i : rhs.terms) {
        terms[i.first] -= i.second;
        if (terms[i.first] == 0) {
            terms.erase(i.first);
        }
    }
    return *this;
}


// Multiplies the current polynomial by a single term represented by 'activeTerms'.
// Returns a new polynomial representing the result of the multiplication.
Polynomial Polynomial::multiply(std::pair<int, int> activeTerms) {
    Polynomial result; // Initialize a polynomial to store the results
    for (std::pair<int, int> i : this->terms) { // Iterate through each term in the polynomial
        int exponent = i.first + activeTerms.first;
        int coefficient = i.second * activeTerms.second;
        result.terms[exponent] = coefficient;
    }
    return result;
}

Polynomial Polynomial::operator*=(const Polynomial& rhs) {
    Polynomial result;  // Initialize a temporary polynomial to store the result

    if (this->terms.empty() || rhs.terms.empty()) {
        this->terms.clear();  // If either of the polynomials is empty, set the current polynomial to zero
        return *this;         // Return the modified polynomial
    }

    Polynomial rhs2 = rhs;  // Create a copy of the right-hand side polynomial

    for (auto e : terms) {
        result += rhs2.multiply(e);  // Multiply each term of the current polynomial by rhs2 and accumulate the result
    }

    *this = result;  // Update the current polynomial with the final result

    return *this;  // Return the modified polynomial
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
    return lhs.terms == rhs.terms;
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