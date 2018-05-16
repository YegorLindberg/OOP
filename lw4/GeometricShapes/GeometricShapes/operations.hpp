//
//  operations.hpp
//  GeometricShapes
//
//  Created by Moore on 16/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef operations_hpp
#define operations_hpp

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "IShape.hpp"
#include "CLineSegment.hpp"
#include "CTriangle.hpp"
#include "CRectangle.hpp"
#include "CCircle.hpp"

void AddLineSegment(std::vector<IShape*>& shapes);
void AddTriangle(std::vector<IShape*>& shapes);
void AddRectangle(std::vector<IShape*>& shapes);
void AddCircle(std::vector<IShape*>& shapes);
size_t TakeGreatestArea(std::vector<IShape*>& shapes);
size_t TakeSmallestPerimeter(std::vector<IShape*>& shapes);

#endif /* operations_hpp */
