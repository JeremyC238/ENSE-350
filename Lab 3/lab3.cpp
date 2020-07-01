
#include <iostream>
#include <cstdlib>
#include "lab3.h"
using namespace std;


int main() {

	// Problem 1

	// Newton-Raphson Method

	cout << "Problem 1 Newton-Raphson Method" << endl << endl;

	double x = 10;
	
	newton_raphson(x);

	cout << endl;

	// Problem 2

	// a) Bisection Method

	cout << "Problem 2 a) Bisection Method" << endl << endl;

	double lower = 0;
	double upper = 1;

	bisection(lower, upper);

	cout << endl;

	// b) Secant Method

	cout << "Problem 2 b) Secant Method" << endl << endl;

	double x1 = 0;
	double x2 = 1;

	secant(x1, x2);

	cout << endl;

	return 0;
}