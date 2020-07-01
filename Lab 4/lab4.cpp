
#include <iostream>
#include "lab4.h"
using namespace std;

int main() {

	// display equations for the program
	cout << "the equations for this program is:" << endl << endl;
	cout << "  3x1 - 2x2 + 3x3 = -10" << endl;
	cout << "  2x1 + 6x2 - 4x3 =  44" << endl;
	cout << " -8x1 - 2x2 + 5x3 = -26" << endl << endl;

	// display the A matrix
	cout << "The A Matrix is:" << endl;
	cout << "      _          _" << endl;
	cout << "     |  3 " << "  2 " << " 3  |" << endl;
	cout << " A = |  2 " << "  6 " << " 4  |" << endl;
	cout << "     |_-8 " << " -2 " << " 5 _|" << endl << endl;

	// create the 2d array for the A matrix
	double a[3][3] = {
		{3, 2, 3},
		{2, 6, -4},
		{-8, -2, 5}
	};

	// creating the matrices for U and L
	double u[3][3];
	double l[3][3];

	LU_decomposition(u, l, a);


	// display the U matrix
	cout << "The U Matrix is:" << endl;
	cout << "      _                       _" << endl;
	cout << "     |  " << u[0][0] << "   " << u[0][1] << "  " << u[0][2] << "        |" << endl;
	cout << " U = |  " << u[1][0] << "   " << u[1][1] << "        " << u[1][2] << "  |" << endl;
	cout << "     |_ " << u[2][0] << "   " << u[2][1] << "         " << u[2][2] << "       _|" << endl << endl;


	//cout << endl;
	//output(u);
	//cout << endl;


	// display the L matrix
	cout << "The L Matrix is:" << endl;
	cout << "      _                        _" << endl;
	cout << "     |   " << l[0][0] << "   " << l[0][1] << "         " << l[0][2] << "        |" << endl;
	cout << " L = |   " << l[1][0] << "   " << l[1][1] << "   " << l[1][2] << "        |" << endl;
	cout << "     |_ " << l[2][0] << "   " << l[2][1] << "   " << l[2][2] << " _|" << endl << endl;


	//cout << endl;
	//output(l);
	//cout << endl;

	return 0;
}