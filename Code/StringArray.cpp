//  StringArray.cpp
//  Task2.10
//
//  Created by MIB on 10/09/16.
//  Copyright © 2016 MIB. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "StringArray.h"

StringArray::StringArray(): words(nullptr), size(0){ }

StringArray::StringArray(char** text, int n) : words(nullptr)
{
    setStringArray(text, n);
}

StringArray::StringArray(const StringArray& source): words(nullptr)
{
    setStringArray(source.words, source.size);
}

StringArray::StringArray(char* text) : words(nullptr),size(0)
{
    setStringArray(text);
}

StringArray::~StringArray()
{
    freeMemory(words,size);
}

int StringArray::getSize() const
{
    return size;
}

void StringArray::setSize(int n)
{
    size = n < 0 ? 0 : n;
}

void StringArray::setStringArray(char** text, int n)
{
    if (words != nullptr) freeMemory(words, size);
    
    int* arr = dimentionsArray(text, n);
    
    size = n;
    words = allocateMemory(size, arr);
    copyArrayWords(words, text, size);
    
    delete [] arr;
}

void StringArray::setStringArray(char* text)
{
    if (text == nullptr || strlen(text) == 0) return;
    
    const char separators[] = "1234567890!@#$%^&*()_+-=,./?;: ";
    char** arr = new char* [strlen(text) / 2];
    char *word = strtok(text,separators);
    int i = 0;
    for(; word ; i++)
    {
        arr[i] = new char[strlen(word) + 1];
        strcpy(arr[i],word);
        word = strtok(nullptr,separators);
    }
    size = i;
    words = arr;
}

StringArray StringArray::concatByElements(const StringArray& other)
{
    int n = size, m = other.size;//вспомагательные локальные переменные
    
    int* arr1 = dimentionsArray(words, n);
    int* arr2 = dimentionsArray(other.words, m);
    
    int maxi = max(n,m), mini = min(n,m);
    char **maxCharArr = max(words,n,other.words,m),
         **minCharArr = min(words,n,other.words,m);
    
    int* maxArr = max(arr1,n,arr2,m), *minArr = min(arr1,n,arr2,m);
    for (int i = 0; i < mini; i++)
    {
        maxArr[i] += minArr[i];
    }
    char** helpArr = allocateMemory(maxi, maxArr);
    copyArrayWords(helpArr,maxCharArr,maxi);
    concatArrayWords(helpArr,minCharArr,mini);
    
    StringArray result(helpArr,maxi);
    
    freeMemory(helpArr,maxi);
    delete [] arr1;
    delete [] arr2;
    
    return result;
}

StringArray StringArray::operator + (const StringArray& other)
{
    return concatByElements(other);
}

StringArray StringArray::operator * (const StringArray& other)
{
    return mergeWithoutDuplication(other);
}

const char* StringArray::operator [] (int i)
{
    if (i < 0 || i > size)
        return nullptr;
    else
        return words[i];
}

StringArray StringArray::operator = (const StringArray& other)
{
    if (&other == this) return *this;
    setStringArray(other.words, other.size);
    return *this;
}

ostream& operator << (ostream& stream, const StringArray& source)
{
    for (int i = 0; i < source.size; i++)
    {
        cout << source.words[i] << endl;
    }
    cout << endl;
    
    return stream;
}

istream& operator >> (istream& stream, StringArray& target)
{
    int n;
    cout << " Введите количество строк: ";
    cin >> n;
    cin.ignore();
    target.setSize(n);
    char** arr = new char*[n];
    for (int i = 0; i < n; i++)
    {
        const int N = 256;
        char temp[N] = "";
        cout << "Введите строку:";
        cin.getline(temp,N,'\n');
        arr[i] = new char[strlen(temp) + 1];
        strcpy(arr[i],temp);
    }
    
    target.words = arr;
    return stream;
}

void StringArray::sortByAlphabet()
{
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; j > i; j--)
            if (strcmp(words[j], words[j - 1]) < 0)
                swap(words[j], words[j - 1]);
}

StringArray StringArray::mergeWithoutDuplication(const StringArray& other)
{
    int n = size, m = other.size;
    char** hlpArr = new char*[n + m];
    int k = 0;
    for (int i = 0; i < n; i++, k++)
    {
        hlpArr[k] = words[i];
    }
    
    for (int i = 0; i < m; i++, k++)
    {
        hlpArr[k] = other.words[i];
    }
    
    char** mrgArr = new char*[n + m];
    k = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (!isSame(hlpArr, i))
        {
            mrgArr[k] = new char[strlen(hlpArr[i]) + 1];
            strcpy(mrgArr[k],hlpArr[i]);
            k++;
        }
    }

    StringArray result(mrgArr,k);
    
    delete [] hlpArr;
    for (int i = 0; i < k; i++)
    {
        delete [] mrgArr[i];
    }
    delete [] mrgArr;
    
    return result;
}

//private methods
void StringArray::freeMemory(char** array, int n)
{
    if (array == nullptr) return;
    for (int i = 0; i < n; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}

char** StringArray::allocateMemory(int n, int* arr)
{
    char** array = new char*[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new char[arr[i] + 1];
    }
    return array;
}

//одномерный массив длины n, элементы которого содержат длины строк массива строк text
int* StringArray::dimentionsArray(char** text, int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int)strlen(text[i]);
    }
    return arr;
}

void StringArray::copyArrayWords(char** destin, char** source, int n)
{
    for (int i = 0; i < n; i++)
    {
        strcpy(destin[i],source[i]);
    }
}

void StringArray::concatArrayWords(char** destin, char** source, int n)
{
    for (int i = 0; i < n; i++)
    {
        strcat(destin[i],source[i]);
    }
}

int StringArray::min(int a, int b)
{
    return a < b ? a : b;
}

char** StringArray::min(char** arr1, int n, char** arr2, int m)
{
    return n < m ? arr1 : arr2;
}

int* StringArray::max(int* arr1, int n, int* arr2, int m)
{
    return n > m ? arr1 : arr2;
}

int* StringArray::min(int* arr1, int n, int* arr2, int m)
{
    return n < m ? arr1 : arr2;
}

char** StringArray::max(char** arr1, int n, char** arr2, int m)
{
    return n > m ? arr1 : arr2;
}

int StringArray::max(int a, int b)
{
    return a > b ? a : b;
}

void StringArray::swap(char*& a, char* &b)
{
    char* temp = a;
    a = b;
    b = temp;
}

bool StringArray::isSame(char** arr, int i)
{
    for (int j = 0; j < i; j++)
    {
        if (strcmp(arr[i],arr[j]) == 0)
            return true;
    }
    return false;
}