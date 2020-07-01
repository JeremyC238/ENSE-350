#include <iostream>
#include "lab6.h"
#include <math.h>
using namespace std;

#define UPPER_BOUND 10.0
#define LOWER_BOUND -10.0
#define TRUE_VALUE 6706.7

double function(double x) {

	// returns the function
	return 2 - 5 * x + 10 * pow(x, 2) + 0.5 * pow(x, 3);
}


double calculate_integral(int n) {

	// h = (b - a)/n
	double h = (UPPER_BOUND - LOWER_BOUND) / n;

	// calculate the inner summation
	double sum = 0;
	for (double innerValue = LOWER_BOUND + h; innerValue < UPPER_BOUND; innerValue += h)
		sum += function(innerValue);

	// Calculate the boundary values and sum them
	return (h / 2) * (function(LOWER_BOUND) + 2 * sum + function(UPPER_BOUND));
}

double true_percent_relative_error(double approx_value) {

	// returns the true percent relative error
	return (TRUE_VALUE - approx_value) / TRUE_VALUE * 100;
}



