#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class lagrange
{
private:
	double *x_values, *y_values;
	int size;
public:
	lagrange()
	{
		int size_1;
		cout << "Lagrange polynomial:\n";
		cout << "\nEnter the number of points: ";

		x_values = new double[size]; 
		y_values = new double[size];

		for (int i = 0; i < size; i++) 
		{
			cout << "x[" << i + 1 << "] = ";
			cin >> x_values[i];
			cout << "y[" << i + 1 << "] = ";
			cin >> y_values[i];
		}
	}
	
	void show()
	{
		cout << "\nx      y\n";
		for (int i = 0; i < size; i++)
		{
			cout << x_values[i] << "      ";
			cout << y_values[i] << "\n";
		}
		cout << endl;
	}

	double InterpolateLagrangePolynomial()
	{
		double lagrange_pol = 0;
		double lagrange_1 = 1;
		double basics_pol;
		double x;
		cout << "Enter x: ";
		cin >> x;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			basics_pol = 1;
			for (int j = 0; j < size; j++)
			{
				if (j == i) continue;
				basics_pol *= (x - x_values[j]) / (x_values[i] - x_values[j]);
				cout << "basics_pol = " << "( " << x << " - " << x_values[j] << " )" << " / " << "( " << x_values[i] << " - " << x_values[j] << " )" << " = " << (x - x_values[j]) / (x_values[i] - x_values[j]) << endl;
			}
			cout << endl;
			lagrange_pol += basics_pol * y_values[i];

			cout << "lagrange_pol = " << basics_pol << " * " << y_values[i]  << " = " << basics_pol * y_values[i] << endl << endl << endl;
		}
		cout << "Answer: " << lagrange_pol << endl;
		return lagrange_pol;
	}
};

int main()
{
	lagrange a;
	a.show();
	a.InterpolateLagrangePolynomial();
	system("pause");
	return 0;
}