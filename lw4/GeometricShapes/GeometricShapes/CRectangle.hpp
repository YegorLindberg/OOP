//
//  CRectangle.hpp
//  TestsGeometricShapes
//
//  Created by Moore on 12/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CRectangle_hpp
#define CRectangle_hpp

#include <stdio.h>
#include "libraries.hpp"
#include "ISolidShape.hpp"

class CRectangle : public ISolidShape
{
public:
    CRectangle(CPoint firstP, CPoint thirdP, double width, double height)
        : m_firstP(firstP), m_thirdP(thirdP), m_width(width), m_height(height)
        {};
    
    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    std::string GetOutlineColor() const;
    std::string GetFillColor() const;
    double GetWidth() const;
    double GetHeight() const;
private:
    CPoint m_firstP;
    CPoint m_thirdP;
    double m_width;
    double m_height;
    std::string m_outlineColor;
    std::string m_fillColor;
};

#endif /* CRectangle_hpp */
