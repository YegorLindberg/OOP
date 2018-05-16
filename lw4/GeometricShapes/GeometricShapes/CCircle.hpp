//
//  CCircle.hpp
//  TestsGeometricShapes
//
//  Created by Moore on 12/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CCircle_hpp
#define CCircle_hpp

#include <stdio.h>
#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <string>

class CCircle : public ISolidShape
{
public:
    CCircle(CPoint center, double radius)
        : m_center(center), m_radius(radius)
    {};

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    std::string GetOutlineColor() const;
    std::string GetFillColor() const;
    CPoint GetCenter() const;
    double GetRadius() const;
private:
    double m_radius;
    CPoint m_center;
    std::string m_outlineColor;
    std::string m_fillColor;
};

#endif /* CCircle_hpp */
