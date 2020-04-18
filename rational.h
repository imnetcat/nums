#pragma once

#include "nums.h"

#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

class Rational : public Nums 
{
public:
	Rational();
	Rational(int num, int denum);

	void setnew(int num, int denum);

	int Numerator() const;
	int Denominator() const;

	void Numerator(int val);
	void Denominator(int val);

	bool operator < (const Rational& rhs) const;
	bool operator == (const Rational& rhs) const;
	bool operator != (const Rational& rhs) const;
	Rational operator + (const Rational& rhs) const;
	Rational operator - (const Rational& rhs) const;
	Rational operator * (const Rational& rhs) const;
	Rational operator / (const Rational& rhs) const;
	friend ostream & operator << (ostream& stream, const Rational& r)
	{
		if (stream.good() || !stream.eof() || stream)
		{
			stream << r.Numerator() << '/' << r.Denominator();
		}
		return stream;
	}
	friend istream & operator >> (istream& stream, Rational& r)
	{
		if (stream.good() || !stream.eof() || stream)
		{
			int num;
			int denum;
			stream >> num;
			stream.ignore(1);	 // "/"
			stream >> denum;
			r.setnew(num, denum);
		}
		return stream;
	}

	bool operator == (int rhs) const;
	bool operator != (int rhs) const;
private:
	int numerator;
	int denominator;
};
