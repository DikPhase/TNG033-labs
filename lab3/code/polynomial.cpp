/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

//Polynomial::Polynomial() : terms{ {{0,0}} } {}

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
		exponentValue = std::max(exponentValue, term.second); // Get the highest value among the second parameters in the vector (exponents)
	}
	return exponentValue;
}


// 
Polynomial::operator std::string() const {
	std::string result = "";
	int counter = 0;
	for (auto it = terms.begin(); it != terms.end(); ++it) { // Loop through the entire terms vector
		
		int coefficient = it->second; // set coefficient as the first element in the vector pair
		int exponent = it->first; // set exponent as the second item in pair pair

		if (coefficient == 0 && exponent == 0) {
			result = "0";
		}

		if (coefficient < 0) { // If coefficient is negativ
			coefficient = std::abs(coefficient);// set abs value of coefficient
			result += std::format(" - {}X^{}", coefficient, exponent); // add negative as string along with coefficient
		}
		else if (it != terms.begin()) { // Check that it isnt the first term
			result += std::format(" + {}X^{}", coefficient, exponent) ; // add positive as string
		}

		if (counter == 0) {
			result += std::format("{}X^{}", coefficient, exponent);
		}
	}
	if (terms.empty()) { // If the vector is empty
		result = "0"; // return 0 as string
	}
	counter++;
	std::cout << result;
	return result;
}