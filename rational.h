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

	bool operator < (const Rational& rhs);
	bool operator == (const Rational& rhs);
	Rational operator + (const Rational& rhs);
	Rational operator - (const Rational& rhs);
	Rational operator * (const Rational& rhs);
	Rational operator / (const Rational& rhs);
	ostream & operator << (ostream& stream);
	istream & operator >> (istream& stream);

private:
	int numerator;
	int denominator;
};
