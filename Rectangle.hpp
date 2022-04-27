#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
    using Shape::Shape;
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle()=delete;
    Rectangle(Rectangle&& rectangle) noexcept=default;
    ~Rectangle() noexcept override = default;

    Rectangle& operator=(Rectangle && other) noexcept = default;
    Rectangle& operator=(const Rectangle & other) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getX() const;
    double getY() const;
    void print() const override;

private:
    double x_=0;
    double y_=0;
};
