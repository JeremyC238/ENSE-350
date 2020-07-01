#include <iostream>
#include "lab1.h"
using namespace std;

int main() {

	// Part 1: build a recursive Euclidean algorithm that computes the gcd of two numbers

	// make sure a is greater then b
    int a = 30;
    int b = 8;
    int result;

    result = euclidean(a, b);
	cout << "Part 1: Euclidean Algorithm" << endl;
	cout <<  "gcd(a, b) = " << result << endl;
	cout << endl;

	// Part 2: build a pulverizer algorithm that solves for the values s and t in gcd(a, b) = sa + tb

	// make sure a is greater than b
	a = 30;
	b = 8;
	int s, t;
	
	// result = gcd
	result = extended_euclidean(a, b, s, t);

	cout << "Part 2: Extended Euclidean Algorithm" << endl;
	cout << "gcd(a, b) = " << result << endl;
	cout << "s = " << s << endl;
	cout << "t = " << t << endl;
	cout << endl;

	// part 3: build a algorithm that takes an fraction and outputs it in lowest terms
	int numerator = 2;
	int denominator = 4;

	cout << "Part 3: Reduced fraction Algorithm" << endl;
	reduced_fraction(numerator, denominator);

	cout << endl;

	return 0;
}