// mainOperationsToVector.cpp : Defines the entry point for the console application.
//
/* 6. Умножить каждый элемент массива на максимальный элемент
 исходного массива и разделить на минимальный элемент исходного массива */

#include <iostream>
#include <vector>
#include <algorithm>
#include "TreatVector.hpp"

using namespace std;

void FillingVector(vector<double>& numerics);
void PrintVector(ostream& output, vector<double>& numerics);

int main()
{
    vector<double> numerics;
    FillingVector(numerics);
    TreatmentVector(numerics);
    sort(numerics.begin(), numerics.end());
    PrintVector(cout, numerics);
    return 0;
}

void FillingVector(vector<double>& numerics)
{
    double value = 0;
    while (cin >> value)
        numerics.push_back(value);
}

void PrintVector(ostream& output, vector<double>& numerics)
{
    for (auto elementOfvec : numerics)
        output << elementOfvec << " ";
    if (!numerics.empty())
        output << "\n";
}
