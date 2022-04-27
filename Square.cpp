#include "Square.hpp"
#include <iostream>

Square::Square(double x)
        : Rectangle(x, x) {}


double Square::getArea() const noexcept {
    return getX() * getX();
}

void Square::print() const {
    std::cout << "Square x: " << getX() << std::endl
              << "Area: " << getArea() << std::endl
              << "Perimeter: " << getPerimeter() << std::endl;
}

double Square::getPerimeter() const noexcept {
    return 4 * getX();
}

