//
//  main.cpp
//  vectorTesting
//
//  Created by Moore on 12/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <stdio.h>

#include "TreatVector.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

const double Accuracy = 0.0001;

bool CheckEqualVec(vector<double>& vector1, vector<double>& vector2)
{
    size_t firstVecLength = vector1.size();
    size_t secondVecLength = vector2.size();
    if (firstVecLength != secondVecLength)
        return false;
    for (size_t i = 0; i < firstVecLength; ++i)
        if (fabs(vector1[i] - vector2[i]) > Accuracy)
            return false;
    return true;
}

vector<double> numbers1 = {};
vector<double> numbers1Result = {};

vector<double> numbers2 = {2};
vector<double> numbers2Result = {2};

vector<double> numbers3 = { 4, 1.1, 16, 8 };
vector<double> numbers3Result = { 58.181, 16, 232.727, 116.363 };

TEST_CASE("Test Treatment vector")
{
    SECTION("Empty Vector")
    {
        TreatmentVector(numbers1);
        CHECK(CheckEqualVec(numbers1, numbers1Result));
    }
    SECTION("Vector with 1 member")
    {
        TreatmentVector(numbers2);
        CHECK(CheckEqualVec(numbers2, numbers2Result));
    }
    SECTION("Usual Test")
    {
        TreatmentVector(numbers3);
        CHECK(CheckEqualVec(numbers3, numbers3Result));
    }
}
