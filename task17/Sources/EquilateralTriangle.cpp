#include "EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int side)
    : Triangle(side, side, side, "�������������� �����������") {
}

bool EquilateralTriangle::check() const {
    
    return Triangle::check() && (a == b && b == c);
}