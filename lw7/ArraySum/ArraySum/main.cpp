//
//  main.cpp
//  ArraySum
//
//  Created by Moore on 23/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>

#include "ArraySum.hpp"

using namespace std;

int main() {
/* то, что находится в комментариях ниже, было сделано для "шаблонной" функции. */
//    {
//        vector<int> intArr = {1, 2, 5, 10, 4, 7};
//        cout << "sum of Numbers(int):\n" << ArraySum<int>(intArr) << "\n------\n";
//
//        vector<int> intErrArr = {1, 2, 5, 10, 4, 7, __INT_MAX__};
//        cout << "sum of Numbers(int) //Err:\n" << ArraySum<int>(intErrArr) << "\n------\n";
//    }
//
//    {
//        vector<double> doubleArr = {1.2, 2.3, 5.1, 10.2, 4.1, 7.1};
//        cout << "sum of Numbers(double):\n" << ArraySum<double>(doubleArr) << "\n------\n";
//
//        vector<double> doubleErrArr = {__DBL_MAX__, 1.2, 2.3, 5.1, 10.2, 4.1, 7.1};
//        cout << "sum of Numbers(double) //Err:\n" << ArraySum<double>(doubleErrArr) << "\n------\n";
//    }
//
//    {
//        vector<string> strArr = {"hi, ", "you are ", "not my friend,", " you are my brother,", " my friend."};
//        cout << "sum of Strings(string):\n" << ArraySum<string>(strArr) << "\n------\n";
//
//        vector<string> strEmptyArr = {};
//        cout << "sum of Strings(string) //Empty:\n" << ArraySum<string>(strEmptyArr) << "\n------\n";
//    }
    
    vector<int> intArr = {1, 2, 5, 10, 4, 7};
    vector<double> doubleArr = {1.2, 2.3, 5.1, 10.2, 4.1, 7.1};
    vector<string> strArr = {"hi, ", "you are ", "not my friend,", " you are my brother,", " my friend."};
    vector<string> strEmptyArr = {};
    
    cout << ArraySum(intArr) << '\n';
    cout << ArraySum(doubleArr) << '\n';
    
    try {
        cout << ArraySum(strArr) << '\n';
        cout << ArraySum(strEmptyArr) << '\n';
    } catch (const std::exception& e) {
        cout << e.what() << '\n';
    }    
    
    return 0;
}
