#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>  // Added for std::pow
#include <format>

// Function to calculate a partial sum for the BBP formula
double calculate(double k) {
    double const factor{ 8.0 * k };
    double const init{ 4.0 / (factor + 1.0) - 1.0 / (factor + 4.0) };

    // Vector to store other factors used in the formula
    std::vector<double> other_factors{ 4.0, 5.0, 6.0 };

    // Apply transformation to other_factors using a lambda function
    std::transform(other_factors.begin(), other_factors.end(), other_factors.begin(), [&factor](double d) { return -1.0 / (d + factor); });

    // Calculate the result using accumulate
    double result{ init };
    result = std::accumulate(other_factors.begin(), other_factors.end(), init);

    return result;
}

int main() {
    // Ask user to enter the number of terms
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    // Vector to store n:th amount of doubles, i.e n = 5: vector with 5 elements
    std::vector<double> terms(n);

    // Initialize terms with consecutive ints using std::iota, i.e 0, 1, 2, 3...
    std::iota(terms.begin(), terms.end(), 0);

    // Create a copy of terms called power_terms, 
    std::vector<double> power_terms{ terms };

    // Apply the calculate function to each element in terms. Second terms.begin() is output iterator, will be overwritten. 
    std::transform(terms.begin(), terms.end(), terms.begin(), calculate);
    // std::transform takes each element in vector and applies 'calculate' function to it.
    // Results are stored in same range, effectively updating the terms vector with calculated values

    // Raise 16 to the power of each element in power_terms
    std::transform(power_terms.begin(), power_terms.end(), power_terms.begin(), [](int i) { return std::pow(16.0, -i); });
    //  [](int i) { return std::pow(16.0, -i); }): Lambda function, takes i as input and returns i to the power of 16
    // [] specifies that what comes after is a anonymous function, 


    // Calculate the inner product of terms and power_terms
    double result{ 0.0 };
    result = std::inner_product(terms.begin(), terms.end(), power_terms.begin(), 0.0);

    // Print the result formatted to 15 decimal places
    std::cout << std::format("{:.15f}\n", result);
}
