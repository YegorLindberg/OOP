//
//  CLineSegment.cpp
//  GeometricShapes
//
//  Created by Moore on 11/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CLineSegment.hpp"
#include "libraries.hpp"

double CLineSegment::GetArea() const
{
    return 0.0;
}

double CLineSegment::GetPerimeter() const
{
    return sqrt(((m_secP.x - m_firstP.x) * (m_secP.x - m_firstP.x)) + ((m_secP.y - m_firstP.y) * (m_secP.y - m_firstP.y)));
}

std::string CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint()
{
    return m_firstP;
}
	
CPoint CLineSegment::GetEndPoint()
{
    return m_secP;
}

std::string CLineSegment::ToString() const
{
    std::ostringstream strStream;
    strStream << "Line Segment:" << "\n"
            << "\t* area = " << GetArea() << "\n"
            << "\t* perimeter = " << GetPerimeter() << "\n"
            << "\t* outline color = " << GetOutlineColor() << "\n";
    return strStream.str();
}


