//
//  main.cpp
//  TestsGeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//
#include <string>
#include "CPoint.hpp"
#include "CCircle.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CLineSegment.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

const double EPSILO = 0.001;

TEST_CASE("Проверка класса CLineSegment")
{
    CPoint firstP;
    firstP.x = 2;
    firstP.y = 2;
    CPoint secP;
    secP.x = 2;
    secP.y = 4;
    string outlineColor = "brown";
    IShape * AB = new CLineSegment(firstP, secP, outlineColor);
    SECTION("Check GetArea:")
    {
        CHECK(AB->GetArea() == 0);
    }
    SECTION("Check GetPerimeter:")
    {
        CHECK(AB->GetPerimeter() == 2);
    }
    SECTION("Check GetOutlineColor:")
    {
        CHECK(AB->GetOutlineColor() == outlineColor);
    }
    SECTION("Check ToString:")
    {
        CHECK(AB->ToString() == "Line Segment:\n\t* area = 0\n\t* perimeter = 2\n\t* outline color = brown\n");
    }
}

TEST_CASE("Проверка класса CTriangle")
{
    CPoint firstP;
    firstP.x = 1;
    firstP.y = 1;
    CPoint secP;
    secP.x = 1;
    secP.y = 4;
    CPoint thirdP;
    thirdP.x = 4;
    thirdP.y = 1;
    string outlineColor = "brown";
    string fillColor = "white";
    IShape * ABC = new CTriangle(firstP, secP, thirdP, outlineColor, fillColor);
    SECTION("Check GetPerimeter(CTriangle):")
    {
        CHECK(ABC->GetPerimeter() <= 10.242 + EPSILO);
        CHECK(ABC->GetPerimeter() >= 10.242 - EPSILO);
    }
    SECTION("Check GetArea(CTriangle):")
    {
        CHECK(ABC->GetArea() <= 4.5 + EPSILO);
        CHECK(ABC->GetArea() >= 4.5 - EPSILO);
    }
}

TEST_CASE("Проверка класса CRectangle")
{
    CPoint firstP;
    firstP.x = 1;
    firstP.y = 1;
    double width = 6;
    double height = 8;
    string outlineColor = "brown";
    string fillColor = "white";
    IShape * ABCD = new CRectangle(firstP, width, height, outlineColor, fillColor);
    SECTION("Check GetPerimeter(CRectangle):")
    {
        CHECK(ABCD->GetPerimeter() == 28);
    }
    SECTION("Check GetArea(CRectangle):")
    {
        CHECK(ABCD->GetArea() == 48);
    }
}

TEST_CASE("Проверка класса CCircle")
{
    CPoint center;
    center.x = 1;
    center.y = 6;
    double radius = 5;
    string outlineColor = "brown";
    string fillColor = "white";
    IShape * O = new CCircle(center, radius, outlineColor, fillColor);
    SECTION("Check GetPerimeter(CCircle):")
    {
        CHECK(O->GetPerimeter() <= 31.415 + EPSILO);
        CHECK(O->GetPerimeter() >= 31.415 - EPSILO);
    }
    SECTION("Check GetArea(CCircle):")
    {
        CHECK(O->GetArea() <= 78.539 + EPSILO);
        CHECK(O->GetArea() >= 78.539 - EPSILO);
    }
}
