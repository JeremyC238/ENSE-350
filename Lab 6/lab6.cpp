#include <iostream>
#include <cstdlib>
#include <math.h>
#include "lab6.h"
#include <fstream>
using namespace std;

int main() {

	int segments;
	ofstream outData;
	outData.open("data.csv");
	
	// user inputs the number of segments
	cout << "input the number of segments" << endl;
	cin >> segments;

	// outputs the result
	cout << "result: " << calculate_integral(segments) << endl;

	// outputs the true value
	cout << "True value: 6706.67" << endl;
	
	// outputs the true percent relative error
	cout << "true percent relative error: " << true_percent_relative_error(calculate_integral(segments)) << endl;

	// values have been printed to the excel file
	cout << "The segments 1 to 1000 and there error have been printed to data.csv" << endl;

	// sets the starting segment to 1
	segments = 1;

	// prints the column headings
	outData << "n" << "," << "error" << endl;

	for (int i = 0; i < 1000; i++) {

		// outputs n values and errors
		outData << segments << "," << true_percent_relative_error(calculate_integral(segments)) << endl;
		segments++;
	}

	outData.close();
	
	return 0;
}