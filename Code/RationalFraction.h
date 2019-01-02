#pragma once
#include <iostream>

using namespace std;

class RationalFraction
{
	friend ostream& operator<<(ostream&, const RationalFraction&);
	//friend istream& operator>>(istream&, RationalFraction&);
public:
	RationalFraction(int = 1, int = 1);
	/*RationalFraction(const RationalFraction&) = default;
	RationalFraction& operator=(const RationalFraction&) = default;*/
	//~RationalFraction() { cout << "Destructor works!" << endl; }
	RationalFraction& operator+(const RationalFraction&) const;
	RationalFraction& operator-(const RationalFraction&) const;
	RationalFraction& operator-() const;
	void SetFraction(int, int);
	int GetNumerator() const;
	int GetDenominator() const;
private:
	int numerator{2};
	int denominator{2};
	void SetNumerator(int);
	void SetDenominator(int);
	static int GCD(int, int);
	static void Reduce(int&, int&);
	static void SignNormalize(int&, int&);
};
