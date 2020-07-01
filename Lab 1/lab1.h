#include <iostream>
using namespace std;

// Part 1
int euclidean(int a, int b) {

	// gcd(a, b) = gcd(b, rem(a, b))

	// the function calls itself recursively until b = 0
	// that means that a = gcd
	if (b == 0) {
		return a;
	}
	
	return euclidean(b, a % b);
}

// Part 2
int extended_euclidean(int a, int b, int &s, int &t) {

	// s*a + t*b = gcd(a, b)
	
	// the function calls itself recursively until b = 0
	// that means that a = gcd
	if (b == 0) {
		s = 1;
		t = 0;
		return a;
	}

	int s1, t1, result = extended_euclidean(b, a % b, s1, t1);

	// The funtion calls unwind and calculate both s and t
	s = t1;
	t = s1 - (a / b) * t1;
	return result;
}

// Part 3
void reduced_fraction(int numerator, int denominator) {

	int newNumerator;
	int newDenominator;

	// prints out original numerator and denominator
	cout << "numerator = " << numerator << endl;
	cout << "denominator = " << denominator << endl;

	// takes both numerator and denominator and divides them by the gcd 
	newNumerator = numerator / euclidean(numerator, denominator);
	newDenominator = denominator / euclidean(numerator, denominator);

	// prints out the new numerator and denominator
	cout << "new numerator = " << newNumerator << endl;
	cout << "new denominator = " << newDenominator << endl;
	
}