// Jeremy Cross
// 200319513
// ENSE Lab 2

#include <iostream>
#include "lab2.h"
using namespace std;

int main() {

	// Step 1: create a function  that generates the GCD between two numbers (euclidean algorithm)
	// Step 2: create a function that generates the s and t values of gcd(a,b) = s*a + t*b (pulverizer algorithm)

	// set a p and q value that are both prime numbers
	int p = 7;
	int q = 13;

	// determine public key (e,n)
	// determine the n value by n = p*q
	// determine the value phi = (p-1)*(q-1)
	int n = p*q;
	int phi = (p - 1)*(q - 1);

	// set an e value
	int e = 4;

	// e must be co-prime to phi (gcd(e, phi) = 1)
	while (e < phi) {
		if (euclidean(e, phi) == 1)
			break;
		else
			e++;
	}

	cout << "public key (e,n): " << "(" << e << "," << n << ")" << endl;

	// determine private key (d,n)
	// d*e = 1(mod phi)
	// e*x + phi*y = 1
	// d = x
	// determine d

	int x, y;
	extended_euclidean(e, phi, x, y);

	int d = x;

	cout << "private key (d,n): " << "(" << d << "," << n << ")" << endl;

	// start encodeing process
	// m' = rem(m^e,n)

	int m = 7;

	cout << "original message is: " << m << endl;

	int m_encrypt = repeated_squaring(m, e, n);

	cout << "encrypted message is: " << m_encrypt << endl;

	// start decrypting process
	// m = rem(m_encrypt^d, n)

	int m_decrypt = repeated_squaring(m_encrypt, d, n);

	// m_decrypt should equal m
	cout << "decrypted message is: " << m_decrypt << endl;

	return 0;
}