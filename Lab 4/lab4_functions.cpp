
#include <iostream>
#include "lab4.h"
using namespace std;

void LU_decomposition(double u[][3], double l[][3], double a[][3]) {

	int n = 3;

	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < n; i++)
	{

		// create the L matrix
		for (j = 0; j < n; j++)
		{
			if (j < i)
				l[j][i] = 0;
			else
			{
				l[j][i] = a[j][i];

				for (k = 0; k < i; k++)
				{
					l[j][i] = l[j][i] - l[j][k] * u[k][i];
				}
			}
		}

		//creates the U matrix
		for (j = 0; j < n; j++)
		{
			if (j < i)
				u[i][j] = 0;
			else if (j == i)
				u[i][j] = 1;
			else
			{
				u[i][j] = a[i][j] / l[i][i];

				for (k = 0; k < i; k++)
				{
					u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
				}
			}
		}
	}
}

void output(double x[][3])
{
	int n = 3;
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			//printf("%f ", x[i][j]);
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

