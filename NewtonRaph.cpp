#include<iostream>
#include<math.h>
using namespace std;
const double NEARLY_ZERO = 1e-40;

double f(double x);
double df(double x);

int main()
{
	double x_init, epsilon, root;
	double x_prev, x_curr, derf;
	int num_iter, max_iter;
	epsilon = 1e-12;
	max_iter = 30;

	cout << "ROOTS OF AN EQUATION USING NEWTON-RAPHSON METHOD" << endl;
	cout << "Please key in an initial guess: ";
	cin >> x_init;
	cout << "Initial guess for the root = " << x_init << endl;
	num_iter = 0;
	x_prev = x_init;
	x_curr = x_init;
	
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
		}

		// Compute new estimate of the root
		x_curr = x_prev - f(x_prev) / derf;
		++num_iter;
		root = x_curr;

		// Check for convergence
		if (fabs(x_curr - x_prev) <= fabs(x_curr * epsilon)) // Eq. 2
		{
			cout << "The root of the equation = " << root << endl;
			cout << "Value of the function at the root, f(" << root << ") = " << f(root) << endl;
			cout << "Number of iterations = " << num_iter << endl;
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
	}
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