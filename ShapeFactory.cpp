//
// Created by tabaluga on 27.04.22.
//

#include "ShapeFactory.h"

template<class ShapeType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments &&... arguments) {
    std::shared_ptr<Shape> shape = std::make_shared<ShapeType>(
            new ShapeType(std::forward<Arguments>(arguments)...));
    return shape;
}