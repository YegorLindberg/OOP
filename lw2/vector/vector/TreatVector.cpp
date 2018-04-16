//  TreatVector.cpp
//  lw2
//
//  Created by Moore on 12/04/2018.
//  Copyright © 2018 Moore. All rights reserved.

#include "TreatVector.hpp"
#include <iostream>
#include <vector>

using namespace std;

void FindExtrema(double& max, double& min, vector<double>& numerics)
{
    for (auto elementOfvec : numerics)
    {
        if (max < elementOfvec)
            max = elementOfvec;
        if (min > elementOfvec)
            min = elementOfvec;
    }
}

void TreatmentVector(vector<double>& numerics)
{
    double maxValue = __DBL_MIN__;
    double minValue = __DBL_MAX__;
    FindExtrema(maxValue, minValue, numerics);
    for (int i = 0; i < numerics.size(); ++i)
        numerics[i] = (numerics[i] * maxValue) / minValue;
    
    //to adjust the values
    for (int i = 0; i < numerics.size(); ++i)
    {
        numerics[i] = (numerics[i] * 1000);
        numerics[i] = static_cast<int>(numerics[i]);
        numerics[i] = (numerics[i] / 1000);
    }
}






















