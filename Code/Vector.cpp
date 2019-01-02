#include "Vector.hpp"

ostream& operator << (ostream& stream, const Vector& vctr)
{
    for (int i = 0; i < vctr.getLength(); i++)
    {
            stream << ' ' << vctr.innerArray[i] << ' ';
    }

    return stream;
}

istream& operator >> (istream& stream, const Vector& vctr)
{
    for (int i = 0; i < vctr.getLength(); i++)
    {
            stream >> vctr.innerArray[i];
    }
    return stream;
}

Vector::Vector(int n) : innerArray(nullptr)
{
    setLength(n);
    
    innerArray = allocateMemory(this->n);
}

Vector::Vector(double* array, int n) : innerArray(nullptr)
{
    setLength(n);
    
    innerArray = allocateMemory(this->n);
    
    for (int i = 0; i < n; i++)
    {
        innerArray[i] = array[i];
    };
}

void Vector::setLength(int n)
{
    this->n = n > 0 ? n : throw "Количество элементов вектора должно быть положительным";
}

double Vector::operator [] (int i)
{
    if (i >= 0 && i <= n)
    {
        return innerArray[i];
    }
    else
    {
        throw "Выход индекса вектора за допустимый диапазон!";
    }
}

Vector::Vector(const Vector& other)
{
    setLength(other.getLength());
    
    innerArray = other.copyToArray();
}

Vector::~Vector()
{
    try
    {
        delete [] innerArray;
    }
    catch (runtime_error &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
}

int Vector::getLength() const
{
    return n;
}

//перегрузка операции присваивания
//не побитовое копирование полей объекта, а глубокое поэлементное копирование элементов массива
//на который указывает поле-указатель объекта
Vector& Vector::operator = (const Vector& other)
{
    if (&other == this)
        return *this;
    
    setLength(other.getLength());
    innerArray = other.copyToArray();//!
    return *this;
}

bool Vector::operator == (const Vector& other) const
{
    if (this->n != other.n)
    {
        return false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (fabs(innerArray[i] - other.innerArray[i]) > accurancy)
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator != (const Vector& other) const
{
    return !(*this == other);
}

//перегрузка операции сложения для двух векторов
Vector Vector::operator + (const Vector& other) const
{
    if (this->n != other.n)
    {
        throw "Невозможно вычислить сумму или разность векторов, для которых размерности не совпадают!";
    }
    
    Vector result(*this);
    for (int i = 0; i < n; i++)
    {
        result.innerArray[i] += other.innerArray[i];
    }
    return result;
}

Vector Vector::operator - (const Vector& other) const
{
    return *this + (-other);
}

//перегрузка унарной операции минус (для упрощения реализации перегрузки вычитания)
Vector Vector::operator - () const
{
    Vector result(*this);
    for (int i = 0; i < n; i++)
    {
        result.innerArray[i] = -result.innerArray[i];
    }
    return result;
}

//перегрузка операции умножения векторов
Vector Vector::operator * (const Vector& other) const
{
    if (n != this->n)
    {
        throw "Невозможно вычислить скалярное произведение векторов, для которых размерности не совпадает!";
    }
    
    Vector result(*this);
    for (int i = 0; i < n; i++)
    {
        result.innerArray[i] = innerArray[i] * other.innerArray[i];
    }
    return result;
}

//перегрузка операции присваивания после вычитания для двух векторов
Vector Vector::operator -= (const Vector& other)
{
    *this = *this - other;
    return *this;
}

//перегрузка операции присваивания после сложения для двух векторов
Vector Vector::operator += (const Vector& other)
{
    *this = *this + other;
    return *this;
}

//перегрузка операции присваивания после умножения для двух векторов
Vector Vector::operator *= (const Vector& other)
{
    return *this * other;
}

//перегрузка операции умножения вектора на число
Vector Vector::operator * (double number) const
{
    int n = this->n;
    
    Vector result(*this);
    for (int i = 0; i < n; i++)
    {
        result.innerArray[i] = number * result.innerArray[i];
    }
    return result;
}

//перегрузка операции деления вектора на число
Vector Vector::operator / (double number) const
{
    return *this * (1. / number);
}

double Vector:: averageElements()
{
    double avrg = 0;
    for (int i = 0; i < n; i++)
    {
        avrg += innerArray[i];
    }
    return avrg / getLength();
}

double Vector:: scalarProduct(Vector& other)
{
    double product = 0;
    
    Vector result = *this * other;
    for (int i = 0; i < n; i++)
    {
        product += result[i];
    }
    
    return product;
}

void Vector::randomVector()
{
    for (int i = 0; i < n; i++)
    {
        innerArray[i] = rand() % 100 / 10.;
    }
}

//функция получения на основе объекта динамического массива
double* Vector::copyToArray() const
{
    int n = getLength();
    
    double* array =  allocateMemory(n);
    
    for (int i = 0; i < n; i++)
    {
        array[i] = this->innerArray[i];
    }
    return array;
}

double* Vector::allocateMemory(int n)
{
    double* array = new double[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
    return array;
}