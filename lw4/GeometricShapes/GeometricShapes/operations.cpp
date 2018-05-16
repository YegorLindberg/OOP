//
//  operations.cpp
//  GeometricShapes
//
//  Created by Moore on 16/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "operations.hpp"

using namespace std;

void AddLineSegment(vector<IShape*>& shapes)
{
    char ch;
    //double value;
    CPoint startP;
    cout << "Enter x to start point: ";
    cin >> startP.x;
    /*
     cin >> ch;
     if (value = static_cast<double>(ch)) //TODO: здесь должна быть проверка на то, число ли это типа дабл?..
     {
     startP.x = value;
     }
     else
     {
     continue;
     }
     */
    cout << "Enter y to start point: ";
    cin >> startP.y;
    CPoint endP;
    cout << "Enter x to end point: ";
    cin >> endP.x;
    cout << "Enter y to end point: ";
    cin >> endP.y;
    string outlineColor1;
    cout << "Enter outline color: ";
    cin >> ch;
    getline(cin, outlineColor1);
    outlineColor1.insert(outlineColor1.begin(), ch);
    IShape * cutCD = new CLineSegment(startP, endP, outlineColor1);
    shapes.push_back(cutCD);
}


void AddTriangle(vector<IShape*>& shapes)
{
    char ch;
    //double value;
    CPoint firstP;
    cout << "Enter x to 1 point: ";
    cin >> firstP.x;
    cout << "Enter y to 1 point: ";
    cin >> firstP.y;
    
    CPoint secP;
    cout << "Enter x to 2 point: ";
    cin >> secP.x;
    cout << "Enter y to 2 point: ";
    cin >> secP.y;
    
    CPoint thirdP;
    cout << "Enter x to 3 point: ";
    cin >> thirdP.x;
    cout << "Enter y to 3 point: ";
    cin >> thirdP.y;
    
    string outlineColor1;
    cout << "Enter outline color: ";
    cin >> ch;
    getline(cin, outlineColor1);
    outlineColor1.insert(outlineColor1.begin(), ch);
    
    string fillColor1;
    cout << "Enter fill color: ";
    cin >> ch;
    getline(cin, fillColor1);
    fillColor1.insert(fillColor1.begin(), ch);
    
    IShape * tirangleABC = new CTriangle(firstP, secP, thirdP, outlineColor1, fillColor1);
    shapes.push_back(tirangleABC);
}

void AddRectangle(vector<IShape*>& shapes)
{
    CPoint mainP;
    cout << "Enter x to main point: ";
    cin >> mainP.x;
    cout << "Enter y to main point: ";
    cin >> mainP.y;
    cout << "Enter width: ";
    double width = 0.0;
    cin >> width;
    cout << "Enter height: ";
    double height = 0.0;
    cin >> height;
    
    char ch = '#';
    string outlineColor;
    cout << "Enter outline color: ";
    cin >> ch;
    getline(cin, outlineColor);
    outlineColor.insert(outlineColor.begin(), ch);
    
    string fillColor;
    cout << "Enter fill color: ";
    cin >> ch;
    getline(cin, fillColor);
    fillColor.insert(fillColor.begin(), ch);
    
    IShape * rectangleABCD = new CRectangle(mainP, width, height, outlineColor, fillColor);
    shapes.push_back(rectangleABCD);
}

void AddCircle(vector<IShape*>& shapes)
{
    CPoint center;
    cout << "Enter x to main point: ";
    cin >> center.x;
    cout << "Enter y to main point: ";
    cin >> center.y;
    
    cout << "Enter radius: ";
    double radius = 0.0;
    cin >> radius;
    
    char ch = '#';
    string outlineColor;
    cout << "Enter outline color: ";
    cin >> ch;
    getline(cin, outlineColor);
    outlineColor.insert(outlineColor.begin(), ch);
    
    string fillColor;
    cout << "Enter fill color: ";
    cin >> ch;
    getline(cin, fillColor);
    fillColor.insert(fillColor.begin(), ch);
    
    IShape * circleO = new CCircle(center, radius, outlineColor, fillColor);
    shapes.push_back(circleO);
}

size_t TakeGreatestArea(vector<IShape*>& shapes)
{
    size_t count = 0;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i]->GetArea() > shapes[count]->GetArea())
        {
            count = i;
        }
    }
    return count;
}

size_t TakeSmallestPerimeter(vector<IShape*>& shapes)
{
    size_t count = 0;
    for (size_t i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i]->GetPerimeter() < shapes[count]->GetPerimeter())
        {
            count = i;
        }
    }
    return count;
}
