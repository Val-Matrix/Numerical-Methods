#include<iostream>
#include<math.h>
using namespace std;
const double NEARLY_ZERO = 1e-40;

double f(double x, double a, double b, double c, double d);
double df(double x, double a, double b, double c);

int main()
{
	double epsilon = 1e-12, x_init, x_prev, x_curr, derf, root, a, b, c, d;
	int num_iter, max_iter;
	char choice;

	cout << "ROOTS OF AN CUBIC EQUATION USING NEWTON-RAPHSON METHOD" << endl;
	cout << "------------------------------------------------------" << endl;
	
	do {
		cout << "Please key in the coefficients for the function f(x) = ax^3 + bx^2 + cx + d." << endl;
		cout << "a = ";
		cin >> a;
		cout << "b = ";
		cin >> b;
		cout << "c = ";
		cin >> c;
		cout << "d = ";
		cin >> d;

		cout << endl << "f(x) = ";
		if (a == -1)
			cout << "- " << "x^3 ";
		else if (a < 0)
			cout << "- " << fabs(a) << "x^3 ";
		else if (a == 1)
			cout << "x^3 ";
		else if (a > 0)
			cout << a << "x^3 ";

		if (b == -1)
			cout << "- " << "x^2 ";
		else if (b < 0)
			cout << "- " << fabs(b) << "x^2 ";
		else if (b == 1)
			cout << "+ x^2 ";
		else if (b > 0)
			cout << "+ " << b << "x^2 ";

		if (c == -1)
			cout << "- " << "x ";
		else if (c < 0)
			cout << "- " << fabs(c) << "x ";
		else if (c == 1)
			cout << "+ x ";
		else if (c > 0)
			cout << "+ " << c << "x ";

		if (d < 0)
			cout << "- " << fabs(d);
		else if (d > 0)
			cout << "+ " << d;

		if (a == 0 && b == 0 && c == 0 && d == 0)
			cout << "0";

		do {
			cout << endl << "Continue with this function? (Y/N): ";
			cin >> choice;
			if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
				cout << "Invalid input. ";
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

		cout << endl;
	} while (choice == 'N' || choice == 'n');
	
	do {
		cout << "Please key in an initial guess: ";
		cin >> x_init;
		cout << "Please key in the maximum number of iterations: ";
		cin >> max_iter;

		cout << endl << "----------------------------------------------------" << endl;
		cout << "Initial guess for the root = " << x_init << endl;
		num_iter = 0;
		root = x_curr = x_prev = x_init;

		while (num_iter < max_iter)
		{
			// Evaluate derivative of function
			derf = df(x_prev, a, b, c);
			if (fabs(derf) <= NEARLY_ZERO)
			{
				cout << "Newton-Raphson method did not converge." << endl;
				cout << "The derivative is close to zero." << endl;
				cout << "The current estimate of the root = " << root << endl;
				cout << "Value of the function at this estimate, f(" << root << ") = " << f(root, a, b, c, d) << endl;
				cout << "Number of iterations = " << num_iter << endl;
				cout << "----------------------------------------------------" << endl;
			}

			// Compute new estimate of the root
			x_curr = x_prev - f(x_prev, a, b, c, d) / derf;
			++num_iter;
			root = x_curr;

			// Check for convergence
			if (fabs(x_curr - x_prev) <= fabs(x_curr * epsilon)) // Eq. 2
			{
				cout << "The root of the equation = " << root << endl;
				cout << "Value of the function at the root, f(" << root << ") = " << f(root, a, b, c, d) << endl;
				cout << "Number of iterations = " << num_iter << endl;
				cout << "----------------------------------------------------" << endl;
				break;
			}

			// Update
			x_prev = x_curr;
		}

		if (num_iter == max_iter)
		{
			cout << "Did not converge after " << max_iter << " iterations." << endl;
			cout << "Current estimate of the root = " << root << endl;
			cout << "Value of the function at the root, f(" << root << ") = " << f(root, a, b, c, d) << endl;
			cout << "----------------------------------------------------" << endl;
		}

		do {
			cout << endl << "Repeat with different initial guess? (Y/N): ";
			cin >> choice;
			if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
				cout << "Invalid input. ";
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

		cout << endl;
	} while (choice == 'Y' || choice == 'y');	
	
	return 0;
}

double f(double x, double a, double b, double c, double d)
{
	double fx;
	fx = a * x * x * x + b * x * x + c * x + d;
	return(fx);
}

double df(double x, double a, double b, double c)
{
	double dfx;
	dfx = 3 * a * x * x + 2 * b * x + c;
	return(dfx);
}