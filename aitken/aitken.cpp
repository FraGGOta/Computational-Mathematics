#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class aitken
{
private:
	double x;
	double *x_values, *y_values;
	int size;
	ifstream f;
public:
	aitken()
	{
		f.open("point.txt");
		f >> size;
		x_values = new double[size];
		y_values = new double[size];

		for (int i = 0; i < size; i++)
		{
			f >> x_values[i];
			f >> y_values[i];
		}
		f >> x;
		f.close();
	}
	void show()
	{
		cout << endl;
		cout << "x";
		cout << setw(9) << "y" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << x_values[i];
			cout << setw(9) << y_values[i] << endl;
		}
		cout << endl;
		cout << "x = " << x << endl << endl;
	}

	double atk(double *x, double *y, int i, int j, double number, int tmp)
	{
		double atk;
		atk = (y[tmp] * (number - x[i]) - y[tmp + 1] * (number - x[j])) / (x[j] - x[i]);
		return atk;
	}

	double calculate() 
	{
		int i = 0, temp = size;
		for (; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++, temp++)
			{
				y_values[temp] = atk(x_values, y_values, i + j + 1, j, x, temp - size + i);
				cout << "P = " << y_values[temp] << endl;
			}
		}
		cout << "\nAnswer: " << y_values[temp - size + i] << endl;
		return x;
	}
};

int main()
{
	aitken a;
	a.show();
	a.calculate();
	system("pause");
	return 0;
}