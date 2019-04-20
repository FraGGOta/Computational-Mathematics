#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define PI 3.14159265359

using namespace std;

class trigonometric
{
private:
	double x, h, n;
	double *x_values, *y_values;
	int size;
	ifstream f;
public:
	trigonometric()
	{
		f.open("point.txt");
		f >> size;
		n = size;
		
		cout << "Trigonometric interpolation" << endl;
		
		x_values = new double[size];
		y_values = new double[size];

		for (int i = 0; i < size; i++)
		{
			f >> x_values[i];
			f >> y_values[i];
		}
		f >> x;
		f.close();
		
		h = x_values[1] - x_values[0];
	}
	void show()
	{
		cout << endl;
		cout << setw(9) << "x  ";
		cout << setw(9) << "y\n";

		for (int i = 0; i < size; i++)
		{
			cout << setw(7) << x_values[i] << "  ";
			cout << setw(8) << y_values[i] << endl;
		}
		cout << endl;
		cout << "x = " << x << endl;
		cout << "h = " << x_values[1] << " - " << x_values[0] << " = " << h << endl << endl;
	}

	double A(int j)
	{
		double a = 0;
		for (int i = 0; i < size - 1; i++) 
		{
			a += y_values[i] * sin(2 * PI * i * j / n);
		}
		a /= n;
		return a;
	}

	double B(int j)
	{
		double b = 0;

		for (int i = 0; i < size - 1; i++) 
		{
			b += y_values[i] * cos(2 * PI * i * j / n);
		}
		b /= n;
		return b;
	}

	void inter_trig()
	{
		if (y_values[0] != y_values[size - 1] || size % 2 == 0)
		{
			cout << "Error" << endl;
			return;
		}
		double y = 0;
		y = B(0);
		cout << "y = " << B(0);
		for (int i = 1; i < size - 1; i++) {

			y += B(i) * cos(2 * PI * i * (x - x_values[0]) / (n * h));
			cout << " + " << B(i) << " * " << cos(2 * PI * i * (x - x_values[0]) / (n * h));
			y += A(i) * sin(2 * PI * i * (x - x_values[0]) / (n * h));
			cout << " + " << A(i) << " * " << sin(2 * PI * i * (x - x_values[0]) / (n * h));
			cout << endl;
		}
		cout << endl << "Answer: " << y << endl << endl;
	}
};

int main()
{
	trigonometric a;
	a.show();
	a.inter_trig();
	system("pause");
	return 0;
}