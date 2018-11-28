#include "Tcalc.h"
#include <iostream>

void main()
{
	TCalculator calc;
	string example;

	cout << "Enter exp" << endl;
	cin >> example;

	calc.SetInf(example);
	calc.ToPost();
	cout << calc.Calcucate() << endl;
}