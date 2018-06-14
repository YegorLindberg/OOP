//
//  main.cpp
//  FindMax
//
//  Created by Moore on 23/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
bool FindMax(vector<T> const& arr, T& maxValue)
{
    bool expression = false;
    size_t dimensions = arr.size();
    if (dimensions != 0)
    {
        expression = true;
        for (size_t i = 0; i < dimensions; ++i)
        {
            if (maxValue < arr[i])
            {
                maxValue = arr[i];
            }
        }
    }
    return expression;
}

template <>
bool FindMax<const char *>(vector<const char*> const& arr, const char * & maxValue)
{
    bool expression = false;
    
    return expression;
}


int main()
{
    vector<int> intArr = {1, 2, 5, 10, 4, 7};
    int maxNum = 0;
    bool summary = FindMax(intArr, maxNum);
    summary ? cout << maxNum << " - max Number(int)\n" : cout << "array is empty.\n";
    
    vector<string> strArr = {"hi", "you are", "you are my brother", "not my friend"};
    string maxStr = "a";
    summary = FindMax(strArr, maxStr);
    summary ? cout << maxStr << " - max String(string)\n" : cout << "array is empty.\n";
    
    vector<const char*> charArr = {"hell", "fine", "some kind of", "purpose"};
    char *maxLink = NULL;
    summary = FindMax(charArr, *maxLink);
    summary ? cout << maxStr << " - max char(const char*)\n" : cout << "array is empty.\n";
    
    
    return 0;
}
