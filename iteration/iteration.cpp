#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define e 0.001

using namespace std;

class matrix
{
private:
	ifstream itr;
	int size;
	double **array_1;
	double *array_2;
public:
	matrix()
	{
		itr.open("matrix.txt");
		itr >> size;
		array_1 = new double*[size];
		for (int i = 0; i < size; i++)
			array_1[i] = new double[size];
		array_2 = new double[size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				itr >> array_1[i][j];
			itr >> array_2[i];
		}
	}

	~matrix()
	{
		itr.close();
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << setw(4) << array_1[i][j] << " ";
			}
			cout << " " << array_2[i] << endl;
		}
	}
	
	void transform()
	{
		double tmp = 0;
		for (int k = 0; k < size; k++)
		{
			for (int i = 0; i < size; i++)
			{
				tmp = array_1[i][i];
				array_2[i] /= tmp;
				for (int j = 0; j <= size; j++)
				{
					array_1[i][j] /= tmp;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			array_2[i];
			for (int j = 0; j < size; j++)
				array_1[i][i] = 0;
		}
	}

	double norm_matrix(double **mas)
	{
		double sum = 0;
		double norm = 0;
		double eps = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum += fabs(mas[i][j]);
				if (sum > norm) norm = sum;
			}
			sum = 0;
		}

		cout << "Norm = " << norm  << endl;
		if (norm > 1)
		{
			cout << "Norm matrix > 1" << endl;
			cout << "The program is completed!" << endl;
			system("pause");
		}

		eps = ((1 - norm) / norm)*e;
		return eps;
	}

	void iteration()
	{
		double *x = new double[size];
		double *x0 = new double[size];
		double *E = new double[size];
		double max = 0, epsilon = 0;

		epsilon = norm_matrix(array_1);

		for (int i = 0; i < size; i++)
			x0[i] = 0;

		int counter = 0;
		do
		{
			counter++;
			cout << "Iteration ¹ " << counter << endl << endl;
			for (int i = 0; i < size; i++)
			{
				x[i] = 0;
				cout << "X" << i + 1 << " = " << array_2[i];
				for (int j = 0; j < size; j++)
				{
					x[i] -= array_1[i][j] * x0[j];
					cout << " - " << array_1[i][j] << " * " << x0[j];
				}
				cout << endl;

				x[i] += array_2[i];
				E[i] = fabs(x[i] - x0[i]);
			}
			cout << endl;
			max = 0;
			for (int i = 0; i < size; i++)
			{
				if (max < E[i]) max = E[i];
				x0[i] = x[i];
				cout << "X" << i + 1 << " = " << x[i] << " " << endl;
			}
			cout << endl;
			cout << "Maximum modulo = " << max << endl << endl;
		} while (max > epsilon);
		cout << endl << "Further, the maximum is less than the specified accuracy\nThe program is completed!" << endl << endl;
		cout << endl << "Result: \n";
		cout << endl << "Number of iterations: " << counter << endl << endl;
		for (int i = 0; i < size; i++)
			cout << "X" << i + 1 << "=" << x[i] << " " << endl;
		delete[] x;
		delete[] x0;
		delete[] E;
	}

	void seidel()
	{
		double *x = new double[size];
		double *x0 = new double[size];
		double *E = new double[size];
		double max = 0, epsilon = 0;

		epsilon = norm_matrix(array_1);
	
		for (int i = 0; i < size; i++)
			x[i] = 0;

		int counter = 0;
		do
		{
			counter++;
			cout << "Iteration ¹ " << counter << endl << endl;
			for (int i = 0; i < size; i++) {
				x[i] = array_2[i];
				cout << "X" << i + 1 << " = " << x[i];

				for (int j = 0; j < size; j++) {
					if (i == j)
						continue;
					x[i] -= array_1[i][j] * x[j];
					cout << " - " << array_1[i][j] << " * " << x[j];
				}
				cout << endl;
				E[i] = fabs(x[i] - x0[i]);
			}
			cout << endl << endl;

			max = 0;
			for (int i = 0; i < size; i++)
			{
				if (max < E[i]) max = E[i];
				x0[i] = x[i];
				cout << "X" << i + 1 << " = " << x[i] << " " << endl;
			}
			cout << endl;
			cout << "Maximum modulo = " << max << endl << endl;
		} while (max > epsilon);
		cout << endl << "Further, the maximum is less than the specified accuracy\nThe program is completed!" << endl << endl;
		cout << endl << "Result: \n";
		cout << endl << "Number of iterations: " << counter << endl << endl;
		for (int i = 0; i < size; i++)
			cout << "X" << i + 1 << "=" << x[i] << " " << endl;
		delete[] x;
		delete[] x0;
		delete[] E;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	matrix a;
	cout << endl << "Matrix: \n" << endl;
	a.Print();
	a.transform();
	cout << endl << "Transformed Matrix\n" << endl;
	a.Print();
	cout << endl;
	cout << endl << "Choose method!" << endl;
	cout << endl << "1)Fixed-point iteration\n\n2)Seidel method" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		a.iteration();
		cout << endl;
	}
	if (choice == 2) {
		a.seidel();
		cout << endl;
	}
	system("pause");
	return 0;
}