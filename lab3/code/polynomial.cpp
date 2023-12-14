/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 *******************************/

#include "polynomial.h"

Polynomial::Polynomial(int coefficient, int exponent) {
	if (coefficient != 0) {
		terms.push_back(std::make_pair(coefficient, exponent));
	}
}

//Polynomial::Polynomial(std::initializer_list<std::pair<int, int>> termList) {
//	for (const auto& term : termList) {
//		int coefficient = term.first;
//		int exponent = term.second;
//
//		if (coefficient != 0) {
//			terms.push_back(std::make_pair(coefficient, exponent));
//		}
//	}
//}

Polynomial::Polynomial(const std::vector<std::pair< int, int>>& termsVector) {
	for (const auto& term : termsVector) {
		int coefficient = term.first;
		int exponent = term.second;

		if (coefficient != 0) {
			terms.push_back(std::make_pair(coefficient, exponent));
		}
	}
}

Polynomial::Polynomial(int constant) : Polynomial(constant, 0) {}

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
	std::string result;

	for (auto it = terms.rbegin(); it != terms.rend(); ++it) { // Loop through the entire terms vector
		int coefficient = it->first; // set coefficient as the first element in the vector pair
		int exponent = it->second; // set exponent as the second item in pair pair

		if (coefficient < 0) { // If coefficient is negativ
			coefficient = std::abs(coefficient); // set abs value of coefficient
			result += " - " + std::to_string(coefficient); // add negative as string along with coefficient
		}
		else if (it != terms.rbegin()) { // Check that it isnt the first term
			result += " + "; // add positive as string
		}

		if (exponent == 0 || coefficient != 1) { 
			result += std::to_string(coefficient);
		}

		if (exponent > 0) { // If exponent is larger than 0
			result += "X"; // Add X
			if (exponent > 1) { // exponent larger than one
				result += "^" + std::to_string(exponent); // add power of exponent
			}
		}
	}
	if (terms.empty()) { // If the vector is empty
		result = "0"; // return 0 as string
	}
	return result;
}