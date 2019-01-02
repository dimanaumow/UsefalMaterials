#pragma once

#pragma once

#include <iostream>
using namespace std; 

#pragma region WorkToArray

#pragma region AllocateMemory
int* AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	return new int[n];
}
#pragma endregion

#pragma region InitMemory
void InitArray(int * const a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int* p = a; p < a + n; p++)
	{
		*p = rand() % 100;
	}
}
#pragma endregion

#pragma region Display
void DisplayArray(const int * a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (const int* p = a; p < a + n; p++)
	{
		std::cout << *p << " ";
	}

	cout << endl; 
}
#pragma endregion

#pragma region FreeMemory
void FreeMemory(int* const a)
{
	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	delete[] a;
}
#pragma endregion
#pragma endregion




#pragma region Remove
void RemoveElement(int * const a, int& n, int k)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (k < 0 || k > n)
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = k; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}

	n--;
}

#pragma endregion




#pragma region WorkToMatrix
#pragma region AllocateMemory
int ** AllocateMemory(int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[d[i]];
	}

	return a;
}
#pragma endregion

#pragma region InitMemory
void InitMatrix(int** a, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}


void InitMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr || d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d[i]; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}
#pragma endregion

#pragma region Display
void DisplayMatrix(int** a, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}

		cout << endl;
	}
}


void DisplayMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	if (d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < d[i]; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}

		cout << endl;
	}
}
#pragma endregion

#pragma region FreeMemory
void FreeMemory(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;
}
#pragma endregion
#pragma endregion




#pragma region Swapped
void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
#pragma endregion



#pragma region QAZWSXEDC



#pragma endregion
