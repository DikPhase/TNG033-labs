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
	//Polynomial();

	Polynomial(int coeff);

	Polynomial(int coefficient = 0, int exponent = 0);

	Polynomial(const std::vector<std::pair<int, int>>& termsVector);
	
	int degree() const;

	explicit operator std::string() const;

private:
	std::map<int,int> terms;
};