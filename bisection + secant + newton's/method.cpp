#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

double function(double function) 
{
	return pow(function, 2) - 3;
}

double fluxion(double function)
{
	return 2 * function;
}

int main() {
	double a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "\nChoose a solution method:\n\n1)Bisection method\n2)Secant method\n3)Newton's method\n\n";

	int check = 0;
	double c = 0; 
	double c1 = 0;
	double epsilon = 0.001; 

	int choice; 
	cin >> choice;
	if (function(b) * function(a) < 0)
	{
		while (true)
		{
			c1 = c;
			if (choice == 1) 
			{
				c = (a + b) / 2;
				cout << "eps = " << "| " << abs(b) << " - " << abs(a) << " |" << " / 2" << " = " << (abs(abs(b) - abs(a)) / 2) << endl;
				cout << "ñ = " << "( " << a << " + " << b << " )" << " / 2" << " = " << c;
				
				if (function(c) * function(b) < 0) 
				{
					cout << "\nf(a) * f(c) = " << function(a) << " * " << function(c) << " = " << function(a) * function(c) << endl;
					cout << "f(c) * f(b) = " << function(c) << " * " << function(b) << " = " << function(c) * function(b) << endl << endl;
					a = c;
				}
				else {
					cout << "\nf(a) * f(c) = " << function(a) << " * " << function(c) << " = " << function(a) * function(c) << endl;
					cout << "f(c) * f(b) = " << function(c) << " * " << function(b) << " = " << function(c) * function(b) << endl << endl;
					b = c;
				}
				if ((abs(abs(b) - abs(a)) / 2) <= epsilon)
					break;
			}
			else if (choice == 2) 
			{
				c = (a * function(b) - b * function(a)) / (function(b) - function(a));
				cout << "c = ( " << a << " * " << function(b) << " - " << b << " * " << function(a) << " )  / " << "( " << function(b) << " - " << function(a) << " ) = " << c;
				
				if (function(c) * function(b) < 0)
				{
					cout << "\nf(a) * f(c) = " << function(a) << " * " << function(c) << " = " << function(a) * function(c) << endl;
					cout << "f(c) * f(b) = " << function(c) << " * " << function(b) << " = " << function(c) * function(b) << endl << endl;
					a = c;
				}
				else {
					cout << "\nf(a) * f(c) = " << function(a) << " * " << function(c) << " = " << function(a) * function(c) << endl;
					cout << "f(c) * f(b) = " << function(c) << " * " << function(b) << " = " << function(c) * function(b) << endl << endl;
					b = c;
				}
				if ((abs(abs(c) - abs(c1)) / 2) <= epsilon)
					break;
			}
			else if (choice == 3)
			{
				if (check == 0)
				{
					cout << "c = c - (function(c) / fluxion(c)\n" << endl;
					check++;
					if (function(a) * fluxion(a) < 0)
						c = b;
					else
						c = a;
					cout << c << " - " << "( " << function(c) << " / " << fluxion(c) << " )" << " = "  << c - (function(c) / fluxion(c)) << endl;
				}
				c = c - (function(c) / fluxion(c));
				if (check != 0)
					cout << c << " - " << "( " << function(c) << " / " << fluxion(c) << " )" << " = " << c - (function(c) / fluxion(c)) << endl;
				
				if ((abs(abs(c) - abs(c1)) / 2) <= epsilon)
					break;
			}
		}
		cout << "The solution is over:  | " << c << " - " << c1 << " | / 2 <= 0,001";
		cout << "\nAnswer: " << c << endl;
	}
	else 
	{
		cout << "\nNo solution";
	}
		system("pause");
	}