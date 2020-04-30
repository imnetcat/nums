#include "rational.h"
#include "matrix.h"
#include "../utest/utest.h"

void test_rational_default_constructor()
{
	const string hint = "Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1";
	Rational r;
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
}

void test_rational_constructor_1()
{
	const string hint = "При конструировании объекта класса Rational с параметрами p и q должно выполняться сокращение дроби p/q";
	Rational r = { 2, 4 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 2, hint);
	r = { 4, 8 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 2, hint);
	r = { 2, 8 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 4, hint);
	r = { 25, 5 };
	Assert(r.Numerator(), 5, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 10, 5 };
	Assert(r.Numerator(), 2, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 10, 10 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 210, 10 };
	Assert(r.Numerator(), 21, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 10, 210 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 21, hint);
	r = { 27, 3 };
	Assert(r.Numerator(), 9, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 3, 27 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 9, hint);
	r = { 34603, 902135 };
	Assert(r.Numerator(), 34603, hint);
	Assert(r.Denominator(), 902135, hint);
	r = { 3, 15 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 5, hint);
}


void test_rational_constructor_2()
{
	const string hint = "Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель";
	Rational r = { -10, 10 };
	Assert(r.Numerator(), -1, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 10, -10 };
	Assert(r.Numerator(), -1, hint);
	Assert(r.Denominator(), 1, hint);
	r = { -10, 5 };
	Assert(r.Numerator(), -2, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 2, -4 };
	Assert(r.Numerator(), -1, hint);
	Assert(r.Denominator(), 2, hint);
	r = { 27, -3 };
	Assert(r.Numerator(), -9, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 3, -27 };
	Assert(r.Numerator(), -1, hint);
	Assert(r.Denominator(), 9, hint);
	r = { -34603, 902135 };
	Assert(r.Numerator(), -34603, hint);
	Assert(r.Denominator(), 902135, hint);
	r = { 3, -15 };
	Assert(r.Numerator(), -1, hint);
	Assert(r.Denominator(), 5, hint);
}

void test_rational_constructor_3()
{
	const string hint = "Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель";
	Rational r = { 1, 5 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 5, hint);
	r = { 10, 10 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 1, hint);
	r = { -10, -10 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 1, hint);
	r = { -2, -4 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 2, hint);
	r = { -3, -27 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 9, hint);
	r = { -34603, -902135 };
	Assert(r.Numerator(), 34603, hint);
	Assert(r.Denominator(), 902135, hint);
	r = { 34603, 902135 };
	Assert(r.Numerator(), 34603, hint);
	Assert(r.Denominator(), 902135, hint);
	r = { 3, 15 };
	Assert(r.Numerator(), 1, hint);
	Assert(r.Denominator(), 5, hint);
}

void test_rational_constructor_4()
{
	const string hint = "Если числитель дроби равен нулю, то знаменатель должен быть равен 1";

	Rational r = { 0, 5 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 25 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 265 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 965 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 3565 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 35715 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 6655 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 12 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 5 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 1 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
	r = { 0, 9090 };
	Assert(r.Numerator(), 0, hint);
	Assert(r.Denominator(), 1, hint);
}

int main()
{
	// TODO: unit-tests

	UTEST test;
	test.run(test_rational_default_constructor, "test rational default constructor");
	test.run(test_rational_constructor_1, "test rational constructor 1");
	test.run(test_rational_constructor_2, "test rational constructor 2");
	test.run(test_rational_constructor_3, "test rational constructor 3");
	test.run(test_rational_constructor_4, "test rational constructor 4");

	system("pause");
	return 0;
}
