#include<iostream>
#include "BigInteger.h"

using namespace std;

BigInteger::BigInteger(BigInteger const& other): size(other.size)
{
	digits = new int[size];
	for (int* p = digits, *q = other.digits; p < digits + size; p++, q++)
	{
		*p = *q;
	}
}

BigInteger::BigInteger(int n)
{
	SetSize(n);

	digits = new int[size];
	for (int* p = digits; p < digits + size; p++)
	{
		//*p = rand() % 10;
		*p = 0;
	}
}

BigInteger::BigInteger(int* a, int n)
{
	SetSize(n);

	digits = new int[size];
	for (int* p = digits, *q = a; p < digits + size; p++, q++)
	{
		*p = *q;
	}
}

BigInteger::~BigInteger()
{
	delete[] digits;
}

int BigInteger::GetSize() const
{
	return size;
}

int BigInteger::CompareTo(BigInteger const &other) const 
{
	if (size > other.size)
		return 1;

	if (size < other.size)
		return -1;

	for (int i = 0; i < size; i++)
	{
		if (digits[i] == other.digits[i])
			continue;
		if (digits[i] > other.digits[i])
			return 1;
		if (digits[i] < other.digits[i])
			return -1;
	}
	return 0;
}

BigInteger BigInteger::Difference(BigInteger const& other) const
{
	BigInteger difference(digits,size);

	for (int i = size - 1; i > 0; i--)
	{
		if (difference.digits[i] < other.digits[i])
		{
			difference.digits[i - 1] -= 1;
			difference.digits[i] += 10;
		}
		difference.digits[i] -= other.digits[i];
	}
	difference.digits[0] -= other.digits[0];
	return difference;
}

BigInteger BigInteger::operator-(BigInteger const& other) const
{
	BigInteger difference(digits, size);

	for (int i = size - 1; i > 0; i--)
	{
		if (difference.digits[i] < other.digits[i])
		{
			difference.digits[i - 1] = difference.digits[i - 1] - 1;
			difference.digits[i] += 10;
		}
		difference.digits[i] -= other.digits[i];
	}
	difference.digits[0] -= other.digits[0];
	return difference;
}

void BigInteger::Display() const
{
	cout << "  ";
	int* p = digits;
	while (*p == 0) 
	{
		cout << " ";
		p++;
	}
	for ( ; p < digits + size; p++)
	{
		cout << *p;
	}
	cout << endl;
}

void BigInteger::SetSize(int n)
{
	if (n < 0) size = N;
	else size = n;
}
