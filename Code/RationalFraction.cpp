#include "stdafx.h"
#include "RationalFraction.h"
#include <stdexcept>

RationalFraction::RationalFraction(int a, int b)
{
	SetFraction(a, b);
}
//RationalFraction& RationalFraction::operator=(const RationalFraction & fraction)
//{
//	SetFraction(fraction.GetNumerator(), fraction.GetDenominator());
//	return *this;
//}
//
//RationalFraction::RationalFraction(const RationalFraction& fraction)
//{
//	SetFraction(fraction.GetNumerator(), fraction.GetDenominator());
//}

RationalFraction& RationalFraction::operator+(const RationalFraction& fraction) const
{
	int nmrtr = GetNumerator() * fraction.GetDenominator() + fraction.GetNumerator() * GetDenominator();
	int dnmtr = GetDenominator() * fraction.GetDenominator();
	RationalFraction result(nmrtr, dnmtr);
	return result;
}

RationalFraction & RationalFraction::operator-(const RationalFraction & fraction) const
{
	RationalFraction temp = -fraction;
	return *this + temp;
}

RationalFraction& RationalFraction::operator-() const
{
	RationalFraction result(-GetNumerator(), GetDenominator());
	return result;
}

void RationalFraction::SetFraction(int a, int b)
{
	Reduce(a, b);
	SignNormalize(a, b);
	SetNumerator(a);
	SetDenominator(b);
}

void RationalFraction::SetNumerator(int value)
{
	numerator = value;
}

void RationalFraction::SetDenominator(int value)
{
	if (value == 0)
	{
		throw std::invalid_argument("Value of denominator can not be zero!");
	}

	denominator = value;
}

int RationalFraction::GetNumerator() const
{
	return numerator;
}

int RationalFraction::GetDenominator() const
{
	return denominator;
}

int RationalFraction::GCD(int a, int b)
{
	b = abs(b);
	a = abs(a);
	return b ? GCD(b, a % b) : a;
}

void RationalFraction::Reduce(int& a, int& b)
{
	int gcd = GCD(a, b);
	a /= gcd;
	b /= gcd;
}

void RationalFraction::SignNormalize(int& a, int& b)
{
	if (b < 0)
	{
		a = -a;
		b = -b;
	}
}

ostream & operator<<(ostream& stream, const RationalFraction& fraction)
{
	if (fraction.GetDenominator() == 1)
	{
		return stream << fraction.GetNumerator();
	}
	else
	{
		return stream << fraction.GetNumerator() << " / " << fraction.GetDenominator();
	}
}

//istream & operator>>(istream& strea, RationalFraction &)
//{
//	// TODO: insert return statement here
//}
