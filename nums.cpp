#include "nums.h"

int Nums::gcd(int a, int b) const
{
	return b ? gcd(b, a % b) : a;
}
int Nums::lcm(int a, int b) const
{
	return (a*b) / gcd(a, b);
}
