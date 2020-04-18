#include "rational.h"

int main()
{
	// TODO: unit-tests

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
