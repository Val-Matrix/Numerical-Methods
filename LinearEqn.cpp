#include<iostream>
#include<cmath>
using namespace std;
const int SIZE = 4;

int main()
{
	double mult, sum;
	int i, j, k, n = SIZE;
	double a[SIZE][SIZE], b[SIZE], x[SIZE];
	char choice;

	cout << "LINEAR ALGEBRAIC EQUATION SOLVING USING NAIVE GAUSS ELIMINATION, Ax = B (4 EQUATIONS)" << endl;
	
	cout << "-------------------------------------------------------------------------------------" << endl;
	do {
		cout << "Please key in the coefficients for matrix A." << endl;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
		}
		cout << endl;

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cout.width(9);
				cout << a[i][j];
			}
			cout << endl;
		}

		do {
			cout << "Continue with this matrix A? (Y/N): ";
			cin >> choice;
			if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
				cout << "Invalid input. ";
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
		
		cout << endl;
	} while (choice == 'N' || choice == 'n');

	cout << "------------------------------------------------" << endl;
	do {
		cout << "Please key in the coefficients for matrix B." << endl;
		for (i = 0; i < n; ++i)
		{
			cout << "b[" << i << "] = ";
			cin >> b[i];
		}
		cout << endl;

		for (i = 0; i < n; ++i)
		{
			cout.width(9);
			cout << b[i];
			cout << endl;
		}

		do {
			cout << "Continue with this matrix B? (Y/N): ";
			cin >> choice;
			if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
				cout << "Invalid input. ";
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
		
		cout << endl;
	} while (choice == 'N' || choice == 'n');

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
		cout << "------------------------------------------------" << endl;
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