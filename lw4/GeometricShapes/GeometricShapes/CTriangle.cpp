//
//  CTriangle.cpp
//  TestsGeometricShapes
//
//  Created by Moore on 12/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CTriangle.hpp"
#include "CPoint.hpp"
#include "math.h"
#include <sstream>
#include <string>

CPoint CTriangle::GetVertex1()
{
    return m_firstP;
}

CPoint CTriangle::GetVertex2()
{
    return m_secP;
}

CPoint CTriangle::GetVertex3()
{
    return m_thirdP;
}

std::string CTriangle::GetFillColor() const
{
    return m_fillColor;
}

std::string CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

double GetDistance(CPoint firstP, CPoint secP)
{
    return sqrt(((secP.x - firstP.x) * (secP.x - firstP.x)) + ((secP.y - firstP.y) * (secP.y - firstP.y)));
}
double CTriangle::GetPerimeter() const
{
    return (GetDistance(m_firstP, m_secP) + GetDistance(m_secP, m_thirdP) + GetDistance(m_thirdP, m_firstP));
}

double CTriangle::GetArea() const
{
    double halfOfPerimeter = GetPerimeter() / 2;
    double firstSide = GetDistance(m_firstP, m_secP);
    double secSide = GetDistance(m_secP, m_thirdP);
    double thirdSide = GetDistance(m_thirdP, m_firstP);
    return sqrt(halfOfPerimeter * (halfOfPerimeter - firstSide) * (halfOfPerimeter - secSide) * (halfOfPerimeter - thirdSide));
}

std::string CTriangle::ToString() const
{
    std::ostringstream strStream;
    strStream << "Triangle:" << "\n"
    << "\t* area = " << GetArea() << "\n"
    << "\t* perimeter = " << GetPerimeter() << "\n"
    << "\t* outline color = " << GetOutlineColor() << "\n"
    << "\t* fill color = " << GetFillColor() << "\n";
    return strStream.str();
}

