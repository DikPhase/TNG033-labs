/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<format>

class Polynomial {
public:
	Polynomial() = default;

	Polynomial(int coeff);

	Polynomial(int coefficient, int exponent);

	Polynomial(const std::vector<std::pair<int, int>>& termsVector);

	Polynomial(const Polynomial& ref) = default;

	~Polynomial() = default;
	
	int degree() const;

	explicit operator std::string() const;

	Polynomial operator+=(const Polynomial& rhs);
	Polynomial operator-=(const Polynomial& rhs);
	Polynomial operator*=(const Polynomial& rhs);
	
	Polynomial multiply(std::pair<int, int> activeTerms) const;

	// Overloaded operators are defined outside class. Friend to access private data members of class
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& P) {
		os << std::string(P);
		return os;
	}

private:
	std::map<int,int> coefficients_table;
};