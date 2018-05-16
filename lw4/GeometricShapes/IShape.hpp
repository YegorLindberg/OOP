//
//  IShape.hpp
//  GeometricShapes
//
//  Created by Moore on 15/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef IShape_h
#define IShape_h

#pragma once

#include <string>

class IShape
{
public:
    virtual ~IShape() = default;
    
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    virtual std::string GetOutlineColor() const = 0;
};


#endif /* IShape_h */
