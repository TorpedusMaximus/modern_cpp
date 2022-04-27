#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
    using Rectangle::Rectangle;
public:
    explicit Square(double x);
    Square(const Square & other) = default;
    Square()=delete;
    Square(Square&& square) noexcept = default;
    ~Square() noexcept override = default;

    Square& operator=(Square && other) noexcept = default;
    Square& operator=(const Square & other) noexcept = default;


    double getY()=delete;
    double getArea() const noexcept override;
    double getPerimeter()const noexcept override;
    void print()const override;

};
