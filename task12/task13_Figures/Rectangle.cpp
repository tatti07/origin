#include "Rectangle.h"

Rectangle::Rectangle(int a_, int b_)
    : Quadrangle(a_, b_, a_, b_, 90, 90, 90, 90) {
    name = "Прямоугольник";
}

bool Rectangle::check() const {
    return Quadrangle::check()
        && (A == 90 && B == 90 && C == 90 && D == 90)
        && (a == c && b == d);
}