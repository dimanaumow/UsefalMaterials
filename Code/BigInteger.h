const int N = 100;

class BigInteger
{
public:
	BigInteger(BigInteger const &);
	BigInteger(int);
	BigInteger(int*, int);
	~BigInteger();
	int GetSize() const;
	int CompareTo(BigInteger const &) const;
	BigInteger Difference(BigInteger const &) const;
	BigInteger operator -(BigInteger const &) const;
	void Display() const;
private:
	int* digits;
	int size;
	void SetSize(int);
};
 