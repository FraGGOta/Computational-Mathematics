#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class gauss
{
private:
	double **array;
	double *x;
	double index, root, b;
	double buff = 0;
	int size, k, c;
	ifstream gs;
public:
	gauss()
	{
		gs.open("matrix.txt");
		gs >> size;
		array = new double*[size];
		x = new double[size];
		for (int i = 0; i < size; ++i) {
			array[i] = new double[size];
			for (int j = 0; j < size + 1; ++j) {
				gs >> array[i][j];
			}
		}
		cout << endl;
	}

	~gauss()
	{
		gs.close();
	}

	void print() 
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size + 1; j++)
			{
				cout << setw(9) << array[i][j] << " ";
			}
			cout << endl;
		}
	}

	void gausss()
	{
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
				cout << "Coeff = " << index << endl;
			}
			cout << endl;
			
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size + 1; j++)
					cout << setw(9) << array[i][j] << " ";
					cout << endl;
			}
			cout << endl;
		}
	}

	void mod_gausss()
	{
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

			c = k;
			for (int i = k + 1; i < size; i++)
				if (abs(array[c][k]) < abs((array[i][k])))
					c = i;

			if (c != k) {
				for (int i = 0; i < size + 1; i++)
				{
					buff = array[c][i];
					array[c][i] = array[k][i];
					array[k][i] = buff;
				}
			}

			for (int e = k + 1; e < size; e++)
			{
				index = array[e][k] / array[k][k];
				for (int l = 0; l < size + 1; l++)
					array[e][l] = array[e][l] - array[k][l] * index;
				cout << "Coeff = " << index  << endl;
			}
			cout << endl;

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size + 1; j++)
					cout << setw(9) << array[i][j] << " ";
					cout << endl;
			}
			cout << endl;
		}
	}

	void inverse() 
	{
		for (int j = size - 1; j >= 0; j--)
		{
			root = array[j][size];
			for (int i = j + 1; i < size; i++)
				root = root - array[j][i] * x[i];
			x[j] = root / array[j][j];
		}
		cout << "Roots:" << endl << endl;
		for (int i = 0; i < size; i++)
			cout << "X" << i + 1 << " = " << x[i] << " " << endl;
	}
};
	
int main()
{
	gauss a;
	cout << "Matrix:\n" << endl;
	a.print();
	cout << "\n1)Gauss Method\n2)Modified gauss method" << endl;
	cout << "Select method: ";
	int choice;
	cin >> choice;
	cout << endl;
	if (choice == 1) {
		a.gausss();
		a.inverse();
		cout << endl;
	}
	if (choice == 2) {
		a.mod_gausss();
		a.inverse();
		cout << endl;
	}
	system("pause");
	return 0;
}