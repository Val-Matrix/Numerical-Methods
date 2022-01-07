#include<iostream>
#include<cmath>
using namespace std;
const int MAXSIZE = 4;

int main()
{
	double mult, sum;
	int i, j, k;
	int n = 3;
	double a[MAXSIZE][MAXSIZE] = { { 225, 0, -25, 0 }, { 0, 175, 0, -125 }, { -225, 0, 275, -50 }, { 0, -25, -250, 275 } };
	double b[MAXSIZE] = { 1400, 100, 2000, 0 };
	double x[MAXSIZE];
	
	// Forward elimination
	for (k = 0; k < n; ++k)
	{
		for (i = k + 1; i < n; ++i)
		{
			mult = a[i][k] / a[k][k];
			b[i] = b[i] - mult * b[k];
			for (j = 0; j < n; ++j)
			{
				a[i][j] = a[i][j] - mult * a[k][j];
			}
		}
		cout << "---------------------------" << endl;
		cout << "k = " << k << ":" << endl;
		cout << "----------" << endl;
		
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cout.width(4);
				cout << a[i][j] << ",";
			}
			cout << "|" << b[i];
			cout << endl;
		}
	}
	
	// Backsubstitution
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (i = n - 1; i > -1; --i)
	{
		sum = 0.0;
		for (j = i + 1; j < n; ++j)
			sum = sum + a[i][j] * x[j];
		x[i] = (b[i] - sum) / a[i][i];
	}
	
	// Display the solution: x0, x1, x2
	cout << "---------------------------" << endl;
	cout << "The solutions..." << endl;
	for (i = 0; i < n; ++i)
		cout << "x[" << i << "] = " << x[i] << endl;
	return 0;
}