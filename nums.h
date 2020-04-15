#pragma once

class Nums 
{
public:
	int gcd(int a, int b) const;
	int lcm(int a, int b) const;
	virtual bool operator == (int) const = 0;
	virtual bool operator != (int) const = 0;
	//virtual bool operator < (double) = 0;
};
