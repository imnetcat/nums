#include "rational.h"
#include "matrix.h"
int main()
{
	// TODO: unit-tests

	Matrix two(1000000, 1);
	Matrix one;

	stringstream s;
	s << "4 4" << endl
		<< "1 0 0 0" << endl
		<< "0 1 0 0" << endl
		<< "0 0 1 0" << endl
		<< "0 0 0 1" << endl;
	s >> one;
	one.At(3, 0) = 2;
	one.At(0, 0) = 2;
	one.At(0, 3) = 2;
	two.At(666666, 0);
	try {
		one.At(4, 0) = 2;
		one.At(4, 3) = 2;
	}
	catch (exception&) {

	}
	cout << one.At(132350, 1) << endl;
	cout << one.At(0, 1) << endl;
	cout << one.At(0, 2) << endl;
	cout << one.At(0, 3) << endl;
	cout << one.At(0, 0) << endl;
	cout << one.At(1, 1) << endl;
	cout << one.At(1, 2) << endl;
	cout << one.At(1, 3) << endl;
	cout << one.At(3, 3) << endl;
	return 0;

	{
		// 
		try
		{
			stringstream stest;
			Rational r1(1, 2);
			stest << r1;
			if (stest.str() != "1/2")
			{

			}
		}
		catch (exception& ex)
		{

		}
	}

	cout << "OK" << endl;
	return 0;
}
