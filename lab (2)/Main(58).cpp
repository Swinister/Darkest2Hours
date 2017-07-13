
// COS30008, Tutorial 3, 2017

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify first polynomial (degree followed by coefficients):" << endl;
	cin >> A;
	cout << "A = " << A << endl;

	Polynomial B;
	cout << "Specify second polynomial (degree followed by coefficients):" << endl;
	cin >> B;
	cout << "B = " << B << endl;

	Polynomial C = A * B;
	cout << "C = A * B = " << C << endl;

	return 0;
}
