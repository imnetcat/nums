#include "rational.h"

Rational::Rational()
{
	setnew(0, 1);
}

Rational::Rational(int num, int denum)
{
	setnew(num, denum);
}

void Rational::setnew(int num, int denum)
{
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

int Rational::Numerator() const
{
	return numerator;
}

int Rational::Denominator() const
{
	return denominator;
}

void Rational::Numerator(int val)
{
	numerator = val;
}

void Rational::Denominator(int val)
{
	denominator = val;
}

bool Rational::operator < (const Rational& rhs)
{
	return (*this - rhs).Numerator() < 0;
}


bool Rational::operator == (const Rational& rhs)
{
	return this->Numerator() == rhs.Numerator() &&
		this->Denominator() == rhs.Denominator();
}

Rational Rational::operator + (const Rational& rhs)
{
	if (this->Denominator() == rhs.Denominator())
	{
		return { this->Numerator() + rhs.Numerator(),
			rhs.Denominator() };
	}
	else {
		int c = lcm(this->Denominator(), rhs.Denominator());
		int a = this->Numerator() * (c / this->Denominator());
		int b = rhs.Numerator() * (c / rhs.Denominator());
		return { a + b, c };
	}
}

Rational Rational::operator - (const Rational& rhs)
{
	if (this->Denominator() == rhs.Denominator())
	{
		return { this->Numerator() - rhs.Numerator(),
			rhs.Denominator() };
	}
	else {
		int c = lcm(this->Denominator(), rhs.Denominator());
		int a = this->Numerator() * (c / this->Denominator());
		int b = rhs.Numerator() * (c / rhs.Denominator());
		return { a - b, c };
	}
}

Rational Rational::operator * (const Rational& rhs)
{
	return { this->Numerator() * rhs.Numerator(),
		this->Denominator() * rhs.Denominator() };
}

Rational Rational::operator / (const Rational& rhs)
{
	if (!this->Denominator() || !rhs.Numerator()) throw domain_error("");
	return { this->Numerator() * rhs.Denominator(),
		this->Denominator() * rhs.Numerator() };
}

ostream & Rational::operator << (ostream& stream)
{
	if (stream.good() || !stream.eof() || stream)
	{
		stream << this->Numerator() << '/' << this->Denominator();
	}
	return stream;
}

istream & Rational::operator >> (istream& stream)
{
	if (stream.good() || !stream.eof() || stream)
	{
		int num;
		int denum;
		stream >> numerator;
		stream.ignore(1);	 // "/"
		stream >> denominator;
		setnew(num, denum);
	}
	return stream;
}