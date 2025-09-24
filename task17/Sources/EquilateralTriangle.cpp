#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int side)
    : Triangle(side, side, side, "Равносторонний треугольник") {
}

bool EquilateralTriangle::check() const {
    
    return Triangle::check() && (a == b && b == c);
}