//
//  main.cpp
//  GeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include "IShape.hpp"
#include "CLineSegment.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CCircle.hpp"
#include "operations.hpp"

using namespace std;

int main()
{
    vector<IShape*> shapes;
    string shape;
    cout << "> ";
    getline(cin, shape);
    while (shape != "exit")
    {
        if (shape == "line segment")
        {
            AddLineSegment(shapes);
        }
        else if (shape == "triangle")
        {
            AddTriangle(shapes);
        }
        else if (shape == "rectangle")
        {
            AddRectangle(shapes);
        }
        else if (shape == "circle")
        {
            AddCircle(shapes);
        }
        else
        {
            cout << "Unknown operation.\n";
        }
        cout << "> ";
        getline(cin, shape);
    }
    if (shapes.size() != 0)
    {
        cout << "Наибольшую площадь имеет фигура:\n" << shapes[TakeGreatestArea(shapes)]->ToString() << endl;
        cout << "Наименьший периметр имеет фигура:\n" << shapes[TakeSmallestPerimeter(shapes)]->ToString() << endl;
    }
    else
    {
        cout << "Массив фигур не был заполнен.\nДо свидания.\n";
    }
    
    return 0;
}

