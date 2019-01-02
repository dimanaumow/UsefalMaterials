//
//  StringArray.h
//  Task2.10
//
//  Created by MIB on 08/09/16.
//  Copyright © 2016 MIB. All rights reserved.
//
#ifndef StringArray_h
#define StringArray_h

#include <iostream>

using namespace std;

class StringArray
{
public:
    StringArray();
    StringArray(char**, int);
    StringArray(char*);
    StringArray(const StringArray&);
    ~StringArray();
    int getSize() const;
    void setStringArray(char**, int);
    void setStringArray(char*);
    StringArray concatByElements(const StringArray&);
    void sortByAlphabet();
    StringArray mergeWithoutDuplication(const StringArray&);
    StringArray operator + (const StringArray&);
    StringArray operator * (const StringArray&);
    const char* operator [] (int);
    StringArray operator = (const StringArray&);
    friend ostream& operator << (ostream&, const StringArray&);
    friend istream& operator >> (istream&, StringArray&);
private:
    //private fields
    char** words;
    int size;
    void setSize(int);
    //private methods-utils
    static char** allocateMemory(int, int*);
    static void freeMemory(char**, int);
    static int* dimentionsArray(char**, int);
    static int max(int, int);
    static int* max(int*, int, int*, int);
    static char** max(char**, int, char**, int);
    static int min(int, int);
    static int* min(int*, int, int*, int);
    static char** min(char**, int, char**, int);
    static void copyArrayWords(char**, char**, int);
    static void concatArrayWords(char** destin, char** source, int n);
    static void swap(char* &, char* &);
    static bool isSame(char**, int);
};

#endif // StringArray_h