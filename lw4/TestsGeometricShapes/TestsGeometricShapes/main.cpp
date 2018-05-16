//
//  main.cpp
//  TestsGeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

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
    CLineSegment AB(firstP, secP);
    SECTION("Check GetArea:")
    {
        CHECK(AB.GetArea() == 2);
    }
    SECTION("Check GetPerimeter:")
    {
        CHECK(AB.GetPerimeter() == 2);
    }
    SECTION("Check SetOutlineColor:")
    {
        AB.SetOutlineColor("green");
        CHECK(AB.GetOutlineColor() == "green");
        string color = "white";
        AB.SetOutlineColor(color);
        CHECK(AB.GetOutlineColor() == color);
    }
    SECTION("Check ToString:")
    {
        AB.SetOutlineColor("blue");
        CHECK(AB.ToString() == "Line Segment:\n\t* area = 2\n\t* perimeter = 2\n\t* outline color = blue\n");
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
    CTriangle ABC(firstP, secP, thirdP);
    SECTION("Check GetPerimeter(CTriangle):")
    {
        CHECK(ABC.GetPerimeter() == 10.242);
    }
    SECTION("Check GetArea(CTriangle):")
    {
        CHECK(ABC.GetArea() == 4.498);
    }
}

TEST_CASE("Проверка класса CRectangle")
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
    CPoint fourthP;
    fourthP.x = 4;
    fourthP.y = 4;
    CRectangle ABCD(firstP, secP, thirdP, fourthP);
    SECTION("Check GetLeftTop(CRectangle):")
    {
        CPoint answer = secP;
        CHECK(ABCD.GetLeftTop().x == answer.x);
        CHECK(ABCD.GetLeftTop().y == answer.y);
    }
    SECTION("Check GetRightTop(CRectangle):")
    {
        CPoint answer = fourthP;
        CHECK(ABCD.GetRightTop().x == answer.x);
        CHECK(ABCD.GetRightTop().y == answer.y);
    }
    SECTION("Check GetRightBottom(CRectangle):")
    {
        CPoint answer = thirdP;
        CHECK(ABCD.GetRightBottom().x == answer.x);
        CHECK(ABCD.GetRightBottom().y == answer.y);
    }
    SECTION("Check Width and Height(CRectangle):")
    {
        CHECK(ABCD.GetWidth() == 3);
        CHECK(ABCD.GetHeight() == 3);
    }
    
    SECTION("Check GetPerimeter(CRectangle):")
    {
        CHECK(ABCD.GetPerimeter() == 12);
    }
    SECTION("Check GetArea(CRectangle):")
    {
        CHECK(ABCD.GetArea() == 9);
    }
}

TEST_CASE("Проверка класса CCircle")
{
    CPoint center;
    center.x = 6;
    center.y = 6;
    double radius = 5;
    CCircle O(center, radius);
    SECTION("Check GetPerimeter(CCircle):")
    {
        CHECK(O.GetPerimeter() == 31.45);
    }
    SECTION("Check GetArea(CCircle):")
    {
        CHECK(O.GetArea() == 78.625);
    }
}
