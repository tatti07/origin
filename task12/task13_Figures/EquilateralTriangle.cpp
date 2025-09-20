#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int side)
    : Triangle(side, side, side, 60, 60, 60) {
    name = "Равносторонний треугольник";
}

bool EquilateralTriangle::check() const {
    return Triangle::check()
        && (a == b && b == c)
        && ( /* A=B=C=60 */ true);
}