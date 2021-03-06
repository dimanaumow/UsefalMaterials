#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

void BlockWriteFile(char*, int, int, int);
void DisplayFile(char*, int, int);
void WorkFile(char*, int, int);
void DisplayMatrix(int*, int, int);
void SimpleMatrix(int*,int, int);
int SumElemMatrix(int*, int, int);
void InitMatrix(int*, int, int);
void SystemFun();

int main()
{
	const int N = 40;
	char fileName[N] = "";
	cout << "\nEnter the name of file: " << endl;
	cin >> fileName;
	int k, n, m;
	while (true)
	{
		cout << "\nEnter k number of matrixs:" << endl;
		cin >> k;
		cout << "\nEnter n, m dimentions of matrixs:" << endl;
		cin >> n >> m;
		if (k > 0 && n > 0 && m > 0)
			break;
		cout << "\nNumber is incorrect! Try again!" << endl;
	}
	system("cls");
	BlockWriteFile(fileName, k, n, m);
	cout << "\nThe contents of file <<" << fileName << ">> :" << endl;
	DisplayFile(fileName, n, m);
	WorkFile(fileName, n, m);
	cout << "\nThe new contents of file <<" << fileName << ">> : " << endl;
	//DisplayFile(fileName, n, m);
	system("pause");
	return 0;
}

void InitMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = rand() % 10;
}

void BlockWriteFile(char* fileName, int k, int n, int m)
{
	ofstream streamOut(fileName, ios::out | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write.";
		SystemFun();
		exit(1);
	}
	int bufSize = sizeof(int) * n * m;
	int* pointer = new int[n * m];
	for (int i = 0; i < k; i++)
	{
		InitMatrix(pointer, n, m);
		streamOut.write((char*)pointer, bufSize);
	}
	delete[] pointer;
	streamOut.close();
}
void DisplayFile(char* fileName, int n, int m)
{
	ifstream streamIn(fileName, ios::in | ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}
	int bufSize = sizeof(int) * n * m, counter = 0;
	int* pointer = new int[n * m];
	while (streamIn.read((char*)pointer, bufSize))
	{
		cout << endl << counter + 1 << "'s  matrix " << endl;
		DisplayMatrix(pointer, n, m);
		counter++;
	}
	delete[] pointer;
	streamIn.close();
}
void DisplayMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(4);
			cout << pointer[i * m + j];
		}
		cout << endl;
	}
}
void SimpleMatrix(int* pointer, int n, int m)
{
	for (int i = 0; i < n * m; i++)
		pointer[i] = 1;
}
int SumElemMatrix(int* pointer, int n, int m)
{
	int summa = 0;
	for (int i = 0; i < n * m; i++)
		summa += pointer[i];
	return summa;
}

void WorkFile(char* fileName, int n, int m)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read.";
		SystemFun();
		exit(1);
	}
	int* pointer = new int[n * m];
	int bufSize = sizeof(int) * n * m;
	int summa = 0;
	while (streamInOut.read((char*)pointer, bufSize))
	{
		summa = SumElemMatrix(pointer, n, m);
		if (summa % 2)
		{
			streamInOut.seekp(-1 * bufSize, ios::cur);
			SimpleMatrix(pointer, n, m);
			streamInOut.write((char*)pointer, bufSize);
			//streamInOut.seekp(bufSize, ios::cur);
		}
	}
	delete[] pointer;
	streamInOut.close();
}
void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}