//
//  main.cpp
//  GeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "libraries.hpp"
#include "CPoint.hpp"
#include "CLineSegment.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CCircle.hpp"
#include "IShape.hpp"

using namespace std;

int main()
{
    
    CPoint A;
    A.x = 1;
    A.y = 1;
    CPoint B;
    B.x = 1;
    B.y = 9;
    string color = "blue";
    IShape * cutAB = new CLineSegment(A, B, color);
    cout << cutAB->ToString() << endl;
    
    /*
    string shape;
    getline(cin, shape);
    while (shape != "exit")
    {
        
    }
    
    */
    delete cutAB;
    
    return 0;
}
