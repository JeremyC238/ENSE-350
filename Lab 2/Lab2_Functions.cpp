#include <iostream>
#include "lab2.h"
using namespace std;

int euclidean(int a, int b) {

	// gcd(a, b) = gcd(b, rem(a, b))

	// the function calls itself recursively until b = 0
	// that means that a = gcd
	if (b == 0) {
		return a;
	}

	return euclidean(b, a % b);
}


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

int repeated_squaring(int base, int exponent, int n) {

	//calcultates the repeated square of m^e mod n for encrypt
	// or m'^d mod n for decrypt

	int result = 1;

	while (exponent > 0) {
		if (exponent % 2 != 0) {
			result = (base*result) % n;
		}
		base = (base*base) % n;
		exponent /= 2;
	}

	return result;

}

