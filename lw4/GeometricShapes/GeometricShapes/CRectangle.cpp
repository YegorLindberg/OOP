//
//  CRectangle.cpp
//  TestsGeometricShapes
//
//  Created by Moore on 12/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//
#include "libraries.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CPoint.hpp"

std::string CRectangle::GetFillColor() const
{
    return m_fillColor;
}

std::string CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CRectangle::GetLeftTop() const
{
    return m_firstP;
}

CPoint CRectangle::GetRightBottom() const
{
    return m_thirdP;
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}

double CRectangle::GetArea() const
{
    return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
    return (GetHeight() + GetWidth()) * 2;
}

std::string CRectangle::ToString() const
{
    std::ostringstream strStream;
    strStream << "Rectangle:" << "\n"
    << "\t* area = " << GetArea() << "\n"
    << "\t* perimeter = " << GetPerimeter() << "\n"
    << "\t* width = " << GetWidth() << "\n"
    << "\t* height = " << GetHeight() << "\n"
    << "\t* outline color = " << GetOutlineColor() << "\n"
    << "\t* fill color = " << GetFillColor() << "\n";
    return strStream.str();
}
