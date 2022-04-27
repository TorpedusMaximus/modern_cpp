#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

Shape::Shape(Color color) {
    this->color = color;
}

Color Shape::getColor() const {
    return this->color;
}

void Shape::setColor(Color co) {
    this->color = co;
}
