//
//  ArraySum.hpp
//  ArraySum
//
//  Created by Moore on 01.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef ArraySum_hpp
#define ArraySum_hpp

#pragma once

#include <vector>
#include <string>

template <typename T>
T ArraySum(std::vector<T> const& arr) {
    T value = T();
    size_t dimensions = arr.size();
    if (dimensions != 0) {
        for (size_t i = 0; i < dimensions; ++i) {
            value += arr[i];
        }
    }
    return value;
}


/* В шаблонных функциях не должны определяться типы, иначе она не будет являться шаблонной. Пример ниже: */

//template <typename T>
//T ArraySum(vector<T> const& arr) {
//    T value = T();
//    size_t dimensions = arr.size();
//    errno = 0;
//    if (dimensions != 0) {
//        if (typeid(value).name() == typeid(string).name()) {
//            for (size_t i = 0; i < dimensions; ++i) {
//                value += arr[i];
//            }
//        } else if ((typeid(value).name() == typeid(int).name()) or (typeid(value).name() == typeid(double).name())) {
//            T MAX_VALUE;
//            if (typeid(value).name() == typeid(int).name()) {
//                MAX_VALUE = __INT_MAX__;
//            } else if (typeid(value).name() == typeid(double).name()) {
//                MAX_VALUE = __DBL_MAX__;
//            }
//            long number = 0;
//            for (size_t i = 0; i < dimensions; ++i) {
//                try {
//                    number = value + arr[i];
//                    if ((errno == ERANGE && number == LONG_MAX) || number <= MAX_VALUE) {
//                        value += arr[i];
//                    } else {
//                        throw overflow_error("Error: Overflow by max value.");
//                    }
//                } catch (overflow_error& err) {
//                    cout << err.what() << "\n";
//                    break;
//                }
//            }
//        } else {
//            cout << "*** Function \"ArraySum\" only for: int, double, string. ***\n";
//        }
//    }
//    return value;
//}

#endif /* ArraySum_hpp */
