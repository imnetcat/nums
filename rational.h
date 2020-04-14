#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}

	Rational(int num, int denum) {
		if (denum == 0)
			throw invalid_argument{ "invalid argument" };
		if (denum < 0)
		{
			num *= -1;
			denum *= -1;
		}

		int g = gcd(abs(num), abs(denum));
		if (g != 1 && g != -1)
		{
			num /= g;
			denum /= g;
		}
		numerator = num;
		denominator = denum;
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

	void Numerator(int val) {
		numerator = val;
	}

	void Denominator(int val) {
		denominator = val;
	}

private:
	int numerator;
	int denominator;
};

bool operator < (const Rational& lhs, const Rational& rhs)
{
	int c = lcm(lhs.Denominator(), rhs.Denominator());
	int a = lhs.Numerator() * (c / lhs.Denominator());
	int b = rhs.Numerator() * (c / rhs.Denominator());
	int d = a - b;
	if (d <= 0 && c < 0)
		return false;
	else if (d >= 0 && c > 0)
		return false;
	else
		return true;
}

bool operator == (const Rational& lhs, const Rational& rhs)
{
	return lhs.Numerator() == rhs.Numerator() &&
		lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator())
	{
		return { lhs.Numerator() + rhs.Numerator(),
			rhs.Denominator() };
	}
	else {
		int c = lcm(lhs.Denominator(), rhs.Denominator());
		int a = lhs.Numerator() * (c / lhs.Denominator());
		int b = rhs.Numerator() * (c / rhs.Denominator());
		return { a + b, c };
	}
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == rhs.Denominator())
	{
		return { lhs.Numerator() - rhs.Numerator(),
			rhs.Denominator() };
	}
	else {
		int c = lcm(lhs.Denominator(), rhs.Denominator());
		int a = lhs.Numerator() * (c / lhs.Denominator());
		int b = rhs.Numerator() * (c / rhs.Denominator());
		return { a - b, c };
	}
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
	return { lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator() };
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
	if (!lhs.Denominator() || !rhs.Numerator()) throw domain_error("");
	return { lhs.Numerator() * rhs.Denominator(),
		lhs.Denominator() * rhs.Numerator() };
}

ostream & operator << (ostream& stream, const Rational& obj)
{
	if (stream.good() || !stream.eof() || stream)
	{
		stream << obj.Numerator() << '/' << obj.Denominator();
	}
	return stream;
}
istream & operator >> (istream& stream, Rational& obj)
{
	int num;
	int denum;
	stream >> num;
	stream.ignore(1);
	stream >> denum;
	if (stream.good() || !stream.eof() || stream)
	{
		obj = Rational(num, denum);
	}
	return stream;
}
int main()
{
	try
	{
		string input;
		Rational r1;
		cin >> r1;
		cin.ignore(1);
		char operation;
		cin >> operation;
		cin.ignore(1);
		Rational r2;
		cin >> r2;

		switch (operation)
		{
		case '+':
			cout << r1 + r2 << endl;
			break;
		case '-':
			cout << r1 - r2 << endl;
			break;
		case '/':
			cout << r1 / r2 << endl;
			break;
		case '*':
			cout << r1 * r2 << endl;
			break;
		default:
			break;
		}
	}
	catch (invalid_argument& ex)
	{
		cout << "Invalid argument" << endl;
	}
	catch (domain_error& ex)
	{
		cout << "Division by zero" << endl;
	}

	return 0;
}