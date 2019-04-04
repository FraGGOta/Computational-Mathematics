#include "newton.h"

int main()
{
	matrix a;
	a.print();
	a.print_fluxion();
	a.iteration();
	system("pause");
	return 0;
}