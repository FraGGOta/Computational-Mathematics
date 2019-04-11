#include "gauss.h"

gauss::gauss(double **c, double *d, int s)
{
	size = s;
	array = new double*[size];
	x = new double[size];
	
	for (int i = 0; i < size; ++i) {
		array[i] = new double[size + 1];
		for (int j = 0; j < size + 1; ++j) {
			if (j == size) {
				array[i][j] = d[i];
			}
			else
				array[i][j] = c[i][j];
		}
	}
	cout << endl;
}

void gauss::print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			cout << setw(12) << array[i][j];
		}
		cout << endl;
	}
}

double* gauss::m_gauss()
{
	print();

	for (k = 0; k < size - 1; k++)
	{
		while (array[k][k] == 0)
		{
			int l, j;
			l = k;
			do
			{
				l = k + 1;
			} while (array[l][k] == 0);

			for (j = k; j <= size; j++)
			{
				b = array[k][j];
				array[k][j] = array[l][j];
				array[l][j] = b;
			}
		}

		for (int e = k + 1; e < size; e++)
		{
			index = array[e][k] / array[k][k];
			for (int l = 0; l < size + 1; l++)
				array[e][l] = array[e][l] - array[k][l] * index;
		}
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size + 1; j++)
				cout << setw(12) << array[i][j];
			cout << endl;
		}
		cout << endl;
	}
	inverse();
	return x;
}

void gauss::inverse()
{
	for (int j = size - 1; j >= 0; j--)
	{
		root = array[j][size];
		for (int i = j + 1; i < size; i++)
			root = root - array[j][i] * x[i];
		x[j] = root / array[j][j];
	}
	cout << "Roots" << endl << endl;
	for (int i = 0; i < size; i++)
		cout << setw(5) << "X" << i + 1 << " = " << x[i] << " " << endl;
}