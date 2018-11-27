#include "Tcalc.h"
#include <iostream>

void main()
{
	TCalculator clc;
	string example;

	cout << "Enter exp" << endl;
	cin >> example;

	clc.SetInf(example);
	clc.ToPost();
	cout << clc.Calcucate() << endl;
}