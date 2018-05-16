//
//  ISolidShape.hpp
//  GeometricShapes
//
//  Created by Moore on 15/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef ISolidShape_hpp
#define ISolidShape_hpp

#pragma once

#include "IShape.hpp"
#include <string>

class ISolidShape : public IShape
{
public:
    virtual std::string GetFillColor() const = 0;
};

#endif /* ISolidShape_hpp */
