#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
const int MAXPOINTS = 15;
const int MAXSIZE = 3;

double poly_leastsqr(double x[], double y[], int num_poly, double *ptr_A0, double *ptr_A1, double *ptr_A2);
void gauss_pivot(double x[][MAXSIZE], double y[], double *ptr_a0, double *ptr_a1, double *ptr_a2);

int main()
{
	cout << "POLYNOMIAL REGRESSION (2ND ORDER POLYNOMIAL)" << endl;
	cout << "--------------------------------------------" << endl;

	double x[MAXPOINTS], y[MAXPOINTS];
	int i;
	int n_poly = 2;
	double ptr_A0, ptr_A1, ptr_A2;
	double err_Y, Sr = 0.0, Sxy, r2;

	x[0] = 1.2;  y[0] = 4.5;
	x[1] = 1.5;  y[1] = 5.1;
	x[2] = 1.8;  y[2] = 5.8;
	x[3] = 2.6;  y[3] = 6.7;
	x[4] = 3.1;  y[4] = 7.0;
	x[5] = 4.3;  y[5] = 7.3;
	x[6] = 4.9;  y[6] = 7.6;
	x[7] = 5.3;  y[7] = 7.4;
	x[8] = 5.7;  y[8] = 7.2;
	x[9] = 6.4;  y[9] = 6.9;
	x[10] = 7.1; y[10] = 6.6;
	x[11] = 7.6; y[11] = 5.1;
	x[12] = 8.6; y[12] = 4.5;
	x[13] = 9.2; y[13] = 3.4;
	x[14] = 9.8; y[14] = 2.7;

	ofstream outputFile;
	outputFile.open("C:\\Users\\Valentino\\Desktop\\Polynomial Regression Result.csv");
	if (!outputFile.is_open())
	{
		cout << "Error opening file." << endl;
		return 0;
	}

	outputFile << "x" << "," << "y" << endl;
	for (i = 0; i < MAXPOINTS; ++i)
		outputFile << x[i] << "," << y[i] << endl;

	// Call polynomial regression function
	err_Y = poly_leastsqr(x, y, n_poly, &ptr_A0, &ptr_A1, &ptr_A2);

	cout << "Display pointer in the main() function" << endl;
	cout << "ptr_A0 = " << ptr_A0 << "\t";
	cout << "ptr_A1 = " << ptr_A1 << "\t";
	cout << "ptr_A2 = " << ptr_A2 << endl << endl;
	
	// Save parabolic data to file
	int nn = 10;
	double xx, yy;
	outputFile << endl << endl << endl;
	outputFile << "xx" << "," << "yy" << endl;
	for (xx = 0; xx < nn; xx += 0.1)
	{
		yy = ptr_A0 + ptr_A1 * xx + ptr_A2 * xx * xx;
		outputFile << xx << "," << yy << endl;
	}
	outputFile.close();

	// Display the solution
	cout << "Therefore, the least-square quadratic equation is:" << endl;
	cout << "y = " << ptr_A0 << " + " << ptr_A1 << "x + " << ptr_A2 << "x^2" << endl << endl;
	
	// Compute the sum of the squares of the residual
	for (i = 0; i < MAXPOINTS; ++i)
		Sr += pow((y[i] - ptr_A0 - ptr_A1 * x[i] - ptr_A2 * x[i] * x[i]), 2);
	cout << "Error_y = " << err_Y << endl;
	cout << "Sr = " << Sr << endl;
	
	// Compute the standard error
	Sxy = sqrt(Sr / ((double)MAXPOINTS - ((double)n_poly + 1)));
	cout << "Standard error = " << Sxy << endl;
	
	// Compute the coefficient of determination
	r2 = (err_Y - Sr) / err_Y;
	cout << "Coefficient of determination, r2 = " << r2 << endl << endl;
	return 0;
}

double poly_leastsqr(double x[], double y[], int num_poly, double *ptr_A0, double *ptr_A1, double *ptr_A2)
{
	double X[MAXSIZE][MAXSIZE]; // Coefficient matrix
	double Y[MAXSIZE];
	double ptr_a0, ptr_a1, ptr_a2;
	double mean_y, error_y;
	int i;
	double sumx = 0.0, sumx2 = 0.0, sumx3 = 0.0, sumx4 = 0.0, sumy = 0.0, sumxy = 0.0, sumx2y = 0.0;

	for (i = 0; i < MAXPOINTS; ++i)
	{
		sumx += x[i];
		sumx2 += pow(x[i], 2);
		sumx3 += pow(x[i], 3);
		sumx4 += pow(x[i], 4);
		sumy += y[i];
		sumxy += x[i] * y[i];
		sumx2y += x[i] * x[i] * y[i];
	}
	mean_y = sumy / MAXPOINTS;
	
	// Finding eror_y
	error_y = 0.0;
	for (i = 0; i < MAXPOINTS; ++i)
		error_y += (y[i] - mean_y) * (y[i] - mean_y);

	cout << "The simultaneous linear equations are:" << endl;
	cout << MAXPOINTS << "\t" << sumx << "\t" << sumx2 << "\t" << "|" << "\t" << sumy << endl;
	cout << sumx << "\t" << sumx2 << "\t" << sumx3 << "\t" << "|" << "\t" << sumxy << endl;
	cout << sumx2 << "\t" << sumx3 << "\t" << sumx4 << "\t" << "|" << "\t" << sumx2y << endl << endl;
	X[0][0] = MAXPOINTS; X[0][1] = sumx; X[0][2] = sumx2;
	X[1][0] = sumx; X[1][1] = sumx2; X[1][2] = sumx3;
	X[2][0] = sumx2; X[2][1] = sumx3; X[2][2] = sumx4;
	Y[0] = sumy; Y[1] = sumxy; Y[2] = sumx2y;
	
	// Call linear equation function (partial pivot Gauss)
	gauss_pivot(X, Y, &ptr_a0, &ptr_a1, &ptr_a2);
	
	// Display pointers
	cout << endl;
	cout << "Display pointer in the poly_leastsqr() function" << endl;
	cout << "ptr_a0 = " << ptr_a0 << "\t";
	cout << "ptr_a1 = " << ptr_a1 << "\t";
	cout << "ptr_a2 = " << ptr_a2 << endl << endl;

	// Passing to pointer in main() function
	*ptr_A0 = ptr_a0;
	*ptr_A1 = ptr_a1;
	*ptr_A2 = ptr_a2;
	return(error_y);
}

void gauss_pivot(double x[][MAXSIZE], double y[], double *ptr_a0, double *ptr_a1, double *ptr_a2)
{
	int i, j, k, l;
	double eps = 1e-30, det = 1.0, temp, mult, sum;
	double a[MAXSIZE];
	
	// Forward elimination
	for (k = 0; k < MAXSIZE; ++k)
	{
		// Search for maximum coefficient in the pivot row
		// a[k][k] in the pivot element
		for (i = k + 1; i < MAXSIZE; ++i)
		{
			if (fabs(x[i][k]) > fabs(x[k][k]))
			{
				// Interchange row containing maximum element with the pivot row
				for (l = 0; l < MAXSIZE; ++l)
				{
					temp = x[i][l];
					x[i][l] = x[k][l];
					x[k][l] = temp;
				}
				temp = y[i];
				y[i] = y[k];
				y[k] = temp;
			}
		}

		// Test for singularity. If the pivot element is smaller than eps, then matrix is singular
		if (fabs(x[k][k]) < eps)
			cout << "Matrix is singular." << endl;
		
		// Compute determinant
		det = det * x[k][k];

		// Eliminate the coefficients of X(I) in rows i+1,...,n
		for (i = k + 1; i < MAXSIZE; ++i)
		{
			mult = x[i][k] / x[k][k];
			y[i] = y[i] - mult * y[k];
			
			for (j = 0; j < MAXSIZE; ++j)
				x[i][j] = x[i][j] - mult * x[k][j];
		}
	}
	
	// Backsubstitution
	for (i = MAXSIZE - 1; i > -1; --i)
	{
		sum = 0.0;
		for (j = i + 1; j < MAXSIZE; ++j)
			sum = sum + x[i][j] * a[j];
		a[i] = (y[i] - sum) / x[i][i];
	}
	
	// Display results
	cout << "Display array in the gauss_pivot() function" << endl;
	cout.precision(4);
	for (i = 0; i < MAXSIZE; ++i)
		cout << "a[" << i << "] = " << a[i] << " ";
	cout << endl;
	
	// Passing to pointer in poly_leastsqr() function
	*ptr_a0 = a[0];
	*ptr_a1 = a[1];
	*ptr_a2 = a[2];
}