#include "gauss.h"

using namespace std;

class spline
{
private:
	double x;
	double *x_values, *y_values;
	double *h;
	double *M;
	double **matrix;
	double *vector;
	int size, i0;
	double S;
	ifstream f;
public:
	spline()
	{
		f.open("point.txt");
		f >> size;
		x_values = new double[size];
		y_values = new double[size];
		h = new double[size - 1];
		M = new double[size];
		matrix = new double*[size - 2];
		vector = new double[size - 2];

		for (int i = 0; i < size - 2; i++)
		{
			matrix[i] = new double[size - 2];
		}

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
		cout << "Spline interpolation" << endl;
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

	void interval()
	{
		for (int i = 0; i < size - 1; i++)
		{
			h[i] = x_values[i + 1] - x_values[i];
			cout << i + 1 << " interval = " << h[i] << endl;
		}
		cout << endl;

		for (int i = 0; i < size - 1; i++)
		{
			if (x > x_values[i] && x < x_values[i + 1])
			{
				i0 = i;
				cout << "The interval = " << i0 + 1 << endl;
			}
		}
	}

	void trasform()
	{
		cout << endl << "Matrix C" << endl << endl;

		for (int i = 0; i < size - 2; i++)
		{
			for (int j = 0; j < size - 2; j++)
			{
				if (i == j)
					matrix[i][j] = (h[i] + h[i + 1]) / 3;
				else if (j == i + 1)
					matrix[i][j] = h[i + 1] / 6;
				else if (j == i - 1)
					matrix[i][j] = h[i] / 6;
				else if (abs(i - j) > 1)
					matrix[i][j] = 0;
				cout << setw(12) << matrix[i][j];
			}
			cout << endl;
		}
	}

	void vector_d()
	{
		cout << endl << "Vector D" << endl;

		for (int i = 0; i < size - 2; i++)
		{
			vector[i] = (y_values[i + 2] - y_values[i + 1]) / h[i + 1] - (y_values[i + 1] - y_values[i]) / h[i + 1];
			cout << endl << "Vector " << i + 1 << " = " << "(( " << y_values[i + 2] << " - " << y_values[i + 1] << " ) / " << h[i + 1] << " ) - (( " << y_values[i + 1] << " - " << y_values[i] << " ) / " << h[i + 1] << " ) = " << vector[i];
		}
		cout << endl << endl;
	}

	void m_spline()
	{
		cout << "Matrix CM=d:\n";
		gauss roots(matrix, vector, size - 2);
		M[0] = 0;
		double *temp_m = new double[size - 2];
		temp_m = roots.m_gauss();
		cout << endl;
		cout << "M" << endl << endl;
		cout << setw(11) << "M[0] = " << M[0] << endl;
		
		for (int i = 1; i < size - 1; i++) 
		{
			M[i] = temp_m[i - 1];
			cout << setw(6) << "M[" << i << "] = " << M[i] << endl;
		}

		M[size] = 0;
		cout << setw(6) << "M[" << size - 1 << "] = " << M[size] << endl;
		S = M[i0] * (pow((x_values[i0 + 1] - x), 3) / (6 * h[i0 + 1])) + M[i0 + 1] * (pow((x - x_values[i0]), 3) / (6 * h[i0 + 1])) + (y_values[i0] - (M[i0] * pow(h[i0 + 1], 2)) / 6)*((x_values[i0 + 1] - x) / h[i0 + 1]) + (y_values[i0 + 1] - (M[i0 + 1] * pow(h[i0 + 1], 2)) / 6)*((x - x_values[i0]) / h[i0 + 1]);
		cout << endl << "Answer" << endl;
		cout << endl << setw(8) << "S = " << S << endl << endl;
	}
};

int main()
{
	spline a;
	a.show();
	a.interval();
	a.trasform();
	a.vector_d();
	a.m_spline();
	system("pause");
	return 0;
}