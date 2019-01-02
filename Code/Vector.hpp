#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>
#include <math.h>

using namespace std;

#define size 5
#define accurancy 0.00000001

class Vector
{
public:
    Vector(int = size);
    Vector(double*, int = size);
    Vector(const Vector&);
    ~Vector();
    void setLength(int);
    int getLength() const;
    Vector& operator = (const Vector&);
    Vector operator + (const Vector&) const;
    Vector operator += (const Vector&);
    Vector operator - () const;
    Vector operator - (const Vector&) const;
    Vector operator -= (const Vector&);
    Vector operator * (const Vector&) const;
    Vector operator *= (const Vector&);
    bool operator == (const Vector&) const;
    bool operator != (const Vector&) const;
    double operator [] (int);
    Vector operator * (double) const;
    Vector operator / (double) const;
    double averageElements();
    void randomVector();
    double scalarProduct(Vector&);
    double* copyToArray() const;
    friend ostream& operator << (ostream&, const Vector&);
    friend istream& operator >> (istream&, const Vector&);
private:
    double* innerArray;
    int n;
    static double* allocateMemory(int);
};


#endif /* Vector_hpp */