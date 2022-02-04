#include<iostream>
#include<math.h>
using namespace std;
const double NEARLY_ZERO = 1e-40;

double f(double x);
double df(double x);

int main()
{
	double epsilon = 1e-12, x_init, x_prev, x_curr, derf, root;
	int num_iter, max_iter;
	char choice;

	cout << "ROOTS OF AN CUBIC EQUATION USING NEWTON-RAPHSON METHOD" << endl;
	cout << "------------------------------------------------------" << endl;
	
	do {
		cout << "Please key in an initial guess: ";
		cin >> x_init;
		cout << "Please key in the maximum number of iterations: ";
		cin >> max_iter;

		cout << endl << "----------------------------------------------------" << endl;
		cout << "Initial guess for the root = " << x_init << endl;
		num_iter = 0;
		x_curr = x_prev = x_init;

		while (num_iter < max_iter)
		{
			// Evaluate derivative of function
			derf = df(x_prev);
			if (fabs(derf) <= NEARLY_ZERO)
			{
				cout << "Newton-Raphson method did not converge." << endl;
				cout << "The derivative is close to zero." << endl;
				cout << "The current estimate of the root = " << root << endl;
				cout << "Value of the function at this estimate, f(" << root << ") = " << f(root) << endl;
				cout << "Number of iterations = " << num_iter << endl;
				cout << "----------------------------------------------------" << endl;
				break;
			}

			// Compute new estimate of the root
			x_curr = x_prev - f(x_prev) / derf;
			++num_iter;
			root = x_curr;

			// Check for convergence
			if (fabs(x_curr - x_prev) <= fabs(x_curr * epsilon))
			{
				cout << "The root of the equation = " << root << endl;
				cout << "Value of the function at the root, f(" << root << ") = " << f(root) << endl;
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
			cout << "Value of the function at the root, f(" << root << ") = " << f(root) << endl;
			cout << "----------------------------------------------------" << endl;
		}
		
		cout << endl;
		
		do {
			cout << "Please select one of the following options:" << endl;
			cout << "1. Repeat with another initial guess" << endl;
			cout << "2. Exit program" << endl;
			cin >> choice;
			cout << endl;
			if (choice != '1' && choice != '2')
				cout << "Invalid input. ";
		} while (choice != '1' && choice != '2');
	} while (choice == '1')
	
	return 0;
}

double f(double x)
{
	double fx;
	fx = 0.5 * x * x * x - 4 * x * x + 6 * x - 2;
	return(fx);
}

double df(double x)
{
	double dfx;
	dfx = 1.5 * x * x - 8 * x + 6;
	return(dfx);
}
