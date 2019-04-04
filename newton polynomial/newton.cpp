#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class newton
{
private:
	double x;
	double *x_values, **y_values;
	double p;
	int size;
	ifstream f;
public:
	newton()
	{
		f.open("point.txt");
		f >> size;
		x_values = new double[size];
		y_values = new double*[size];

		for (int i = 0; i < size; i++) {
			y_values[i] = new double[size - i];
		}

		for (int i = 0; i < size; i++)
		{
			f >> x_values[i];
			f >> y_values[0][i];
		}
		f >> x;
		f.close();

		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				y_values[i][j] = y_values[i - 1][j + 1] - y_values[i - 1][j];
			}
		}
	}
	
	void show()
	{
		cout << endl;
		cout << setw(9) << "x";
		cout << setw(9) << "y";

		for (int i = 1; i < size; i++) {
			cout << setw(8) << "dy" << i;
		}
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << setw(9) << x_values[i];
			for (int j = 0; j < size - i; j++) {
				cout << setw(9) << y_values[j][i];
			}
			cout << endl;
		}
		cout << endl;
		cout << "x = " << x << endl << endl;
	}

	double factorial(int n)
	{
		if (n == 0)
			return 1;
		return n * factorial(n - 1);
	}

	double Stap(int size)
	{
		double temp = (x - x_values[0]) / (x_values[1] - x_values[0]);
		for (int i = 1; i < size; i++)
			temp *= ((x - x_values[0]) / (x_values[1] - x_values[0])) - i;
		return temp;
	}

	void inter_newton()
	{
		p = y_values[0][0];
		cout << "P = " << y_values[0][0];
		for (int i = 1; i < size; i++) {
			p += y_values[i][0] / factorial(i) * Stap(i);
			cout << " + (" << y_values[i][0] << " / " << factorial(i) << ") * " << Stap(i);
		}
		cout << " = " << p << endl << endl;
		cout << "Answer: " << p << endl << endl;
	}
};

int main()
{
	newton a;
	a.show();
	a.inter_newton();
	system("pause");
	return 0;
}