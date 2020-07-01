
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "lab3.h"
using namespace std;

#define E0 8.85E-12 
#define Q 2E-5
#define q 2E-5
#define F 1
#define a 0.9
#define PI 3.14159265358979323846

// Problem 1 Newton-Raphson Method functions

double function_1(double x) {

	// returns the function
	double numerator = (q * Q * x);
	double denominator = (4 * PI * E0) * pow((pow(x, 2) + pow(a, 2)), (3 / 2.0));
	return (numerator / denominator) - F;
}

double function_1_derivative(double x) {

	// returns the derivative of the function
	double numerator = q * Q * (pow(a, 2) - 2 * pow(x, 2));
	double denominator = (4 * PI * E0) * pow((pow(a, 2) + pow(x, 2)), (5 / 2.0));
	return (numerator / denominator) - F;
}

double calculate_error(double current, double previous) {

	// returns the absolute relative approximate error using the formula 
	return ((abs(current - previous) / current)) * 100;
}

void newton_raphson(double x) {

	// x(i+1) = x(i) - f(x) / f'(x)

	double prevX = x; // previous x value
	double currX; // current x value
	double approx_error = 0.01;

	while (approx_error >= 0.01) {

		// use equation to solve for x(i+1)
		currX = prevX - (function_1(prevX) / function_1_derivative(prevX));

		// calculate error
		approx_error = calculate_error(currX, prevX);

		// print the value value
		cout << "the x value for this iteration is: " << currX << endl;

		// update previous x value
		prevX = currX;	
	}
}

// Problem 2 a) Bisection Method Functions

double function_2(double x) {

	// function: 230x^4 + 18x^3 + 9x^2 - 221x - 9
	return (230 * x*x*x*x + 18 * x*x*x + 9 * x*x - 221 * x - 9);
}

void bisection(double l, double u) {

	// f(l) * f(u) < 0

	/*
	if (function(l) * function(u) >= 0) {
		cout << "You have choosen incorrect lower and upper values" << endl;
		//return;
	}
	*/
		
	double m; // declare midpoint
	double approx_error = 0.01;

	// loop while error is greater or equal to 0.01
	while (approx_error >= 0.01) {

		// find the mid point
		m = (l + u) / 2;

		// calculate error for this iteration
		approx_error = calculate_error(u, l);

		// check if the mid point is the root
		// if so then break out of loop
		if (function_2(m) == 0.0)
			break;

		// decide the sides to repeat the steps
		else if (function_2(m) * function_2(l) < 0)
			u = m; // uses the left side
		else
			l = m; // uses the right side
	}

	cout << "the value of the root is: " << m << endl;
}

// Problem 2 b) Secant Method Functions

void secant(double x1, double x2) {

	/*
	if (function(x1) * function(x2) >= 0) {
		cout << "You have choosen incorrect x1 and x2 values" << endl;
		return;
	}
	*/

	double x;
	double n = 1; // keeps track of the number of iterations
	double approx_error = 0.01;

	// loop while error is greater or equal to 0.01
	while (approx_error >= 0.01) {

		// estimate the root using formula
		x = x1 - (function_2(x1)*(x1 - x2)) / (function_2(x1) - function_2(x2));

		// output current iteration values
		cout << "the current root estimation value for iteration " << n << " is: " << x << endl;

		// calculate the error for this iteration
		approx_error = calculate_error(x1, x2);
		cout << "the error for iteration " << n << " is: " << approx_error << endl;

		n++; // increment iteration

		// update the values for x1 and x2 for the next iteration
		x1 = x2;
		x2 = x;
	}

	cout << "the value of the root is: " << x << endl;
}