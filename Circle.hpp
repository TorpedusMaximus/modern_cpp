#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
    using Shape::Shape;
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle() = delete;
    Circle(Circle && circle) noexcept = default;
    ~Circle() noexcept override = default;

    Circle& operator=(const Circle & other) noexcept = default;
    Circle& operator=(Circle && other) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    void print() const override;
    [[deprecated]]
    double getPI();
private:
    double r_=0;
};
