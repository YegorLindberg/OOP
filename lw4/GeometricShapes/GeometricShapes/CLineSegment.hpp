//
//  CLineSegment.hpp
//  GeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CLineSegment_hpp
#define CLineSegment_hpp

#pragma once

#include <stdio.h>
#include "CPoint.hpp"
#include "IShape.hpp"

class CLineSegment : public IShape
{
public:
    CLineSegment(CPoint firstP, CPoint secP, std::string outlineColor)
        : m_firstP(firstP), m_secP(secP), m_outlineColor(outlineColor)
    {};
    CPoint GetStartPoint();
    CPoint GetEndPoint();
    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    std::string GetOutlineColor() const;
private:
    CPoint m_firstP;
    CPoint m_secP;
    std::string m_outlineColor;
};

#endif /* CLineSegment_hpp */
