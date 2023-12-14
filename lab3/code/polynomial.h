/*******************************
 * Lab 3: exercise 2            *
 * Polynomial class             *
 * Header file                  *
 *******************************/
#include<vector>
#include<iostream>
#include<string>

class Polynomial {
public:
	Polynomial(int coefficient = 0, int exponent = 0);
	explicit Polynomial(int constant);
	/*Polynomial(std::initializer_list<std::pair<int, int>> termList);*/
	Polynomial(const std::vector<std::pair<int, int>>& termsVector);
	int degree() const;

	explicit operator std::string() const;

private:
	std::vector<std::pair<int, int>> terms;
};