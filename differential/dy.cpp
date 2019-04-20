#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double function(double y, double x)
{
	return y - pow(x, 2);
}

int main()
{
	double y;
	double h = 0.1; 
	double dy = 3;
	double answer = 0;
	int size = 10; 
	cout << "Differential equation" << endl;
	cout << "Euler method" << endl << endl;
	cout << endl << "h = " << h << endl;
	cout << "y(0) = " << dy << endl << endl;
	y = dy;

	for (int i = 0; i < size; i++) 
	{
		dy = y + h * function(dy, i * h);
		cout << "dy = " << y << " + " << h << " * " << function(dy, i * h) << " = " << dy << endl;
		y = y + h / 2 * (function(y, i * h) + function(dy, (i + 1) * h));
		cout << "y = " << y << " + ( " << h << " / 2 ) * ( " << function(y, i * h) << " + " << function(dy, (i + 1) * h) << " ) = " << y << endl << endl;
	}

	cout << endl << "Answer = " << y << endl;
	system("pause");
}