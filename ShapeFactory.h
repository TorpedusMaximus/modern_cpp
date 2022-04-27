//
// Created by tabaluga on 27.04.22.
//

#include <memory>
#include "Shape.hpp"

#ifndef MODERN_CPP_SHAPEFACTORY_H
#define MODERN_CPP_SHAPEFACTORY_H

#endif //MODERN_CPP_SHAPEFACTORY_H

template<class ShapeType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args);

