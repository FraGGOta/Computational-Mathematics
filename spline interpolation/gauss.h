#pragma once
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
public:
	gauss(double **c, double *d, int s);
	void print();
	double* m_gauss();
	void inverse();
};

