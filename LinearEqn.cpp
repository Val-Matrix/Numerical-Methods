#include<iostream>
#include<cmath>
using namespace std;
const int SIZE = 4;

int main()
{
	double mult, sum;
	int i, j, k, n = SIZE;
	double a[SIZE][SIZE] = { { 225, 0, -25, 0 }, { 0, 175, 0, -125 }, { -225, 0, 275, -50 }, { 0, -25, -250, 275 } };
	double b[SIZE] = { 1400, 100, 2000, 0 };
	double x[SIZE];
	
	cout << "LINEAR ALGEBRAIC EQUATION SOLVING USING NAIVE GAUSS ELIMINATION, Ax = B (4 EQUATIONS)" << endl;
	
	// Forward elimination
	for (k = 0; k < n; ++k)
	{
		for (i = k + 1; i < n; ++i)
		{
			mult = a[i][k] / a[k][k];
			b[i] = b[i] - mult * b[k];
			for (j = 0; j < n; ++j)
				a[i][j] = a[i][j] - mult * a[k][j];
		}
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "k = " << k << ":" << endl;
		cout << "--------" << endl;
		
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cout.width(9);
				cout << a[i][j];
			}
			cout << " | " << b[i];
			cout << endl;
		}
		cout << endl;
	}
	
	// Backward substitution
	for (i = n - 1; i > -1; --i)
	{
		sum = 0;
		for (j = i + 1; j < n; ++j)
			sum = sum + a[i][j] * x[j];
		x[i] = (b[i] - sum) / a[i][i];
	}
	
	// Display the solution: x0, x1, x2
	cout << "------------------------------------------------" << endl;
	cout << "Solution:" << endl;
	for (i = 0; i < n; ++i)
		cout << "x[" << i << "] = " << x[i] << endl;
	return 0;
}