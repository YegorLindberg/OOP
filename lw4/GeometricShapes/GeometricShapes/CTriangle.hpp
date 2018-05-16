//
//  CTriangle.hpp
//  TestsGeometricShapes
//
//  Created by Moore on 12/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CTriangle_hpp
#define CTriangle_hpp

#pragma once

#include <stdio.h>
#include "CPoint.hpp"
#include "ISolidShape.hpp"

class CTriangle : public ISolidShape
{
public:
    CTriangle(CPoint firstP, CPoint secP, CPoint thirdP, std::string outlineColor, std::string fillColor)
        : m_firstP(firstP), m_secP(secP), m_thirdP(thirdP), m_outlineColor(outlineColor), m_fillColor(fillColor)
    {};
    CPoint GetVertex1();
    CPoint GetVertex2();
    CPoint GetVertex3();
    
    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    std::string GetOutlineColor() const;
    std::string GetFillColor() const;
private:
    CPoint m_firstP;
    CPoint m_secP;
    CPoint m_thirdP;
    std::string m_outlineColor;
    std::string m_fillColor;
};

double GetDistance(CPoint firstP, CPoint secP);

#endif /* CTriangle_hpp */
