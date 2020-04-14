#include "nums.h"
#include "rational.h"

int main()
{
	// TODO: unit-tests

	{
		// Тестирование работы рациональных дробей
		try
		{
			// тестирование конструктора
			Rational r1;
			if (r1.Denominator() != 1 || r1.Numerator() != 0)
			{

			}
		}
		catch (exeption& ex)
		{

		}
	}

	return 0;
}
